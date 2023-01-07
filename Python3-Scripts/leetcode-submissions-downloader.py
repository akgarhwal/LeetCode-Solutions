import helper
import time
import constants
from datetime import datetime
import sys, getopt

# Variables
questionTitleSlugToFrontendQuestionIdDict = {}
questionTitleSlugToDifficultyLevelDict = {}
totalQuestionCount = 0

# Functions
def processSubmission(submission):
    title_slug = submission.get("title_slug")
    frontendQuestionId = questionTitleSlugToFrontendQuestionIdDict[title_slug]
    if submission != None:
        status = helper.processAndWriteSubmission(submission, frontendQuestionId)
    return status


def fetchMetaDataAndPrepareDict():
    allProblemsMetaDataResponse = helper.fetchMetaDataForAllProblems()
    # also write it to file and save this api call 
    # helper.writeToFile("AllProblemsMetaDataResponse.json", json.dumps(allProblemsMetaDataResponse))

    totalQuestionCount=allProblemsMetaDataResponse.get("num_total")
    print("Total Question Count: {0}".format(totalQuestionCount))

    statStatusPairsList = helper.getStatStatusPairsList(allProblemsMetaDataResponse)
    for questionMetaDataRes in statStatusPairsList:
        title_slug = helper.getQuestionTitleSlugFromRes(questionMetaDataRes)
        difficulyLevel = helper.getDifficultyLevelFromRes(questionMetaDataRes)
        frontendQuestionId = helper.getFrontendQuestionIdFromRes(questionMetaDataRes)

        questionTitleSlugToFrontendQuestionIdDict[title_slug] = frontendQuestionId
        questionTitleSlugToDifficultyLevelDict[title_slug] = difficulyLevel

def main(argv):
    fetchMetaDataAndPrepareDict()
    fetchAll = False
    argsValue = ""
    opts, args = getopt.getopt(argv,"ha:")
    for opt, arg in opts:
        if opt == '-h':
            print ('leetcode-submissions-downloader.py -a <True|False>')
            sys.exit()
        elif opt in ("-a"):
            argsValue = arg

    fetchAll = argsValue == "True"
    print("Fetch All: {0}".format(fetchAll))

    time.sleep(3)
    count = 0
    isNewSubmissionsProcessed = False
    responseJson = helper.fetchRecentSubmissionsForQuestion()

    fetchNextPage = True
    offset = 0
    limit = constants.GET_SUBMISSIONS_LIMIT
    while fetchNextPage:
        submissionsDump = helper.getSubmissionsDump(responseJson)
        for submission in submissionsDump:
            count += 1
            title_slug = submission.get("title_slug")
            print("Start processing title-slug: " + title_slug)
            isProcessed = processSubmission(submission)
            if not isProcessed:
                isNewSubmissionsProcessed = True
                print("Queestion: {0} is not processed becuase file already present".format(title_slug))

            if isNewSubmissionsProcessed and not fetchAll:
                break;

            print("Completed processing title-slug: " + title_slug)
        
        if not fetchAll and isNewSubmissionsProcessed:
            print("Fetching new sobmissions is completed.")
            break
        
        # wait for 1 seconds
        print("\n\n Wait for 5 seconds...\n\n")
        time.sleep(5)
        fetchNextPage = helper.getHasNext(responseJson)
        # fetchNextPage = False
        if fetchNextPage:
            lastKey = helper.getLastKey(responseJson)
            offset = offset + limit
            print("\n\nFetch next page offset:{0}, limit={1}\n\n".format(offset, limit))
            responseJson = helper.fetchRecentSubmissionsForQuestion(offset, limit, lastKey)

    print("Processed total {0} submissions.".format(count))


## Script Start
startTime = datetime.now()
print("Started - {0}".format(startTime))


if __name__ == "__main__":
   main(sys.argv[1:])

endTime = datetime.now()
print("Completed - {0}".format(endTime))
print("Time taken - {0}".format(endTime-startTime))


