import helper
import time
import json

# Variables
questionTitleSlugToFrontendQuestionIdDict = {}
questionTitleSlugToDifficultyLevelDict = {}
totalQuestionCount = 0

# Functions
def fetchAndProcessQuestionSubmissions(title_slug):
    print("Start processing title-slug: " + title_slug)
    frontendQuestionId = questionTitleSlugToFrontendQuestionIdDict[title_slug]

    jsonResponse = helper.fetchSubmissionsForQuestion(title_slug)
    submissionsDump = helper.getSubmissionsDump(jsonResponse)

    # print(jsonResponse)
    # print(submissionsDump)
    
    if submissionsDump == None:
        print("Question: " + title_slug + " has no submission.")

    if submissionsDump != None:
        acceptedSubmission = helper.getFirstAcceptedSubmission(submissionsDump)

        if acceptedSubmission != None:
            helper.processAndWriteSubmission(acceptedSubmission, frontendQuestionId)
            print("Question: " + title_slug + " has processed successfully.")
        else:
            print("Question: " + title_slug + " has no accepted submission")
    
    print("Completed processing title-slug: " + title_slug)

allProblemsMetaDataResponse = helper.fetchMetaDataForAllProblems()

# also write it to file and save this api call 
helper.writeToFile("AllProblemsMetaDataResponse.json", json.dumps(allProblemsMetaDataResponse))

totalQuestionCount=allProblemsMetaDataResponse.get("num_total")
print("Total Question Count: {0}".format(totalQuestionCount))


statStatusPairsList = helper.getStatStatusPairsList(allProblemsMetaDataResponse)

# print("List: ")
# print(statStatusPairsList)

for questionMetaDataRes in statStatusPairsList:

    title_slug = helper.getQuestionTitleSlugFromRes(questionMetaDataRes)
    difficulyLevel = helper.getDifficultyLevelFromRes(questionMetaDataRes)
    frontendQuestionId = helper.getFrontendQuestionIdFromRes(questionMetaDataRes)

    questionTitleSlugToFrontendQuestionIdDict[title_slug] = frontendQuestionId
    questionTitleSlugToDifficultyLevelDict[title_slug] = difficulyLevel

count = 0
# Now fetch Summissions for each question
for title_slug in questionTitleSlugToFrontendQuestionIdDict.keys():

    fetchAndProcessQuestionSubmissions(title_slug)
    time.sleep(0.4)
    count += 1
    if count % 100 == 0:
        print("{0}/{1}".format(count, totalQuestionCount))

print("{0}/{1}".format(count, totalQuestionCount))
print("Done!!!")

