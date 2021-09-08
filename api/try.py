import requests
import json


user_agent = 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36'
url = "https://leetcode.com/api/problems/all/"

headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
resp = requests.get(url, headers = headers, timeout = 10)

question_list = json.loads(resp.content.decode('utf-8'))
f = open('get_ac.sh', 'w')

for question in question_list['stat_status_pairs']:
    if question["status"] == "ac":
    	str1 = "leetcode submission {} -o submission/ \n".format(question['stat']["frontend_question_id"])
    	str2 = "sleep 5s\n"
    	f.write(str1)
    	f.write(str2)
f.close()
    	