import os
import requests
import json
import auth
import constants as const


# Helper Functions

# Save the content to a file with the filename"
def writeToFile(filename, content):
    with open(f'{filename}', 'w') as f:
        f.write(content)

# Get File Extension for Languages like .cpp for C++
def getFileExtensionFromLang(lang): 
    langToFileExtensionDict = {
        "cpp" : ".cpp",
        "golang": ".go",
        "csharp": ".cs",
        "javascript": ".js",
        "java": ".java",
        "mssql": ".sql"
    }
    return langToFileExtensionDict[lang]

def getFileName(submission, frontendQuestionId):
    title_slug = submission.get("title_slug")
    lang = submission.get("lang")
    lang_name = submission.get("lang_name")

    fileName = "{0}{1}-{2}{3}".format(getSolutionDirPath(lang_name), str(frontendQuestionId), title_slug, getFileExtensionFromLang(lang))
    return fileName

def getSolutionDirPath(lang_name):
    relPath = "../Solutions/{0}/".format(lang_name)
    # Check whether the specified path exists or not
    isExist = os.path.exists(relPath)
    if not isExist:
        # Create a new directory because it does not exist
        os.makedirs(relPath)
    return relPath

def fetchMetaDataForAllProblems():
    """ 
    # Response Structure for example
    {
        "user_name": "akgarhwal",
        "num_solved": 316,
        "num_total": 2519,
        "ac_easy": 104,
        "ac_medium": 174,
        "ac_hard": 38,

        "stat_status_pairs": [
            {
                "stat": {
                    "question_id": 2658,
                    "question__article__live": null,
                    "question__article__slug": null,
                    "question__article__has_video_solution": null,
                    "question__title": "Count the Number of K-Big Indices",
                    "question__title_slug": "count-the-number-of-k-big-indices",
                    "question__hide": false,
                    "total_acs": 232,
                    "total_submitted": 315,
                    "frontend_question_id": 2519,
                    "is_new_question": true
                },
                "status": null,
                "difficulty": {
                    "level": 3
                },
                "paid_only": true,
                "is_favor": false,
                "frequency": 0,
                "progress": 0
            },
            ..... more data here ......
        ],
        "frequency_high": 0,
        "frequency_mid": 0,
        "category_slug": "all"
    }
    """

    # Get the meta data for all problems
    response = requests.get(
        const.ALL_PROBLEMS_META_DATA_API_ENDPOINT, 
        headers={ "Cookie": auth.Cookie }
    )
    jsonResponse = response.json()
    return jsonResponse

def getQuestionTitleSlugFromRes(jsonRes):
    return jsonRes.get("stat").get("question__title_slug")

def getFrontendQuestionIdFromRes(jsonRes):
    return jsonRes.get("stat").get("frontend_question_id")

def getDifficultyLevelFromRes(jsonRes):
    difficultyLevelDict = {
        1: "Easy",
        2: "Medium",
        3: "Hard" 
    }
    return difficultyLevelDict[jsonRes.get("difficulty").get("level")]

def getStatStatusPairsList(jsonRes):
    return jsonRes.get("stat_status_pairs")

def fetchSubmissionsForQuestion(titleSlug, offset = 0, limit = 100):
    """
    {
        "submissions_dump": [
            {
                "id": 868506086,
                "lang": "cpp",
                "lang_name": "C++",
                "time": "33 minutes",
                "timestamp": 1672481357,
                "status": 10,
                "status_display": "Accepted",
                "runtime": "6 ms",
                "url": "/submissions/detail/868506086/",
                "is_pending": "Not Pending",
                "title": "Unique Paths III",
                "memory": "7.1 MB",
                "code": "class Solution {\npublic:\n\n    int R[4] = {-1, 0, 1, 0};\n    int C[4] = {0, 1, 0, -1};\n\n    bool canWalk(int x, int y, vector<vector<int>>& grid) {\n        if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {\n            return false;\n        }\n        if(grid[x][y] != -1 and grid[x][y] != 5) {\n            return true;\n        }\n        return false;\n    }\n\n    vector<pair<int,int>> path;\n\n    // void printPath(){\n    //     for(pair<int,int> pi : path){\n    //         cout<<\" (\"<<pi.first<<\", \"<<pi.second<<\") \";\n    //     }\n    //     cout<<endl;\n    // }\n\n    void solve(int x, int y, vector<vector<int>>& grid, int& pathLen, int curPathLen, int& ans) {\n        // cout<<curPathLen<<\"   \"<<grid[x][y]<<\"    \";\n        // printPath();\n        \n        for(int d = 0; d < 4; d++){\n            int nx = x + R[d];\n            int ny = y + C[d];\n\n            if(canWalk(nx, ny, grid)) {\n\n                if(curPathLen+1 == pathLen && grid[nx][ny] == 2){\n                    ans += 1;\n                    continue;\n                }\n\n                // path.push_back({nx,ny});\n\n                int temp = grid[nx][ny];\n                grid[nx][ny] = 5;\n                solve(nx, ny, grid, pathLen, curPathLen+1, ans);\n                grid[nx][ny] = temp;\n\n                // path.pop_back();\n            }\n        }\n    }\n    int uniquePathsIII(vector<vector<int>>& grid) {\n        int x, y, ans = 0, pathLen = 0;\n        int curPathLen = 0;\n        // path.clear();\n\n        for(int i = 0; i < grid.size(); i++) {\n            for(int j = 0; j < grid[0].size(); j++) {\n                if(grid[i][j] == 1) {\n                    x = i; y = j;\n                    grid[x][y] = 5; // 5 means already walk over this grid.\n                }\n                if(grid[i][j] == 0) {\n                    pathLen += 1;\n                }\n            }\n        }\n        pathLen += 1;\n        // path.push_back({x,y});\n        solve(x, y, grid, pathLen, curPathLen, ans);\n\n        return ans;\n    }\n};",
                "compare_result": "111111111111111111111111111111111111111",
                "title_slug": "unique-paths-iii",
                "has_notes": false,
                "notes": "",
                "topic_tags": []
            }
        ],
        "has_next": false,
        "last_key": ""
    }
    """
    # Get the list of submissions for a title-slug
    response = requests.get(    
        const.SUBMISSIONS_API_ENDPOINT + titleSlug + "/?offset=0&limit=20", 
        headers = { "Cookie": auth.Cookie }
    )
    jsonResponse = response.json()
    return jsonResponse

def getSubmissionsDump(jsonRes):
    return jsonRes.get("submissions_dump")


def getFirstAcceptedSubmission(submissionsDump):
    for submission in submissionsDump:
        if submission.get("status_display") == "Accepted":
            return submission
    return None

def processAndWriteSubmission(submission, frontendQuestionId):
    writeToFile(
        getFileName(submission, frontendQuestionId), 
        getCotentWithCodeAndMetaData(submission, frontendQuestionId)
    )


def getCotentWithCodeAndMetaData(submission, frontendQuestionId):
    sid = submission.get("id")
    runtime = submission.get("runtime")
    memory = submission.get("memory")
    title = submission.get("title")
    title_slug = submission.get("title_slug")
    code = submission.get("code")
    lang_name = submission.get("lang_name")

    content = (
        "/*\nProblem Title: {0} - {1}\nLang: {2}\nRuntime: {3}\nMemory: {4}\nProblem Url: {5}\nSubmission Url: {6}\n*/\n\n{7}"
        .format(str(frontendQuestionId), title, lang_name, runtime, memory, const.PROBLEMS_URL_PREFIX + title_slug, const.PROBLEMS_URL_PREFIX + title_slug + "/submissions/" + str(sid), code)
    )

    return content
