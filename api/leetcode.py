import json
import csv
from collections import OrderedDict
import pandas as pd

with open('data.json', 'r') as j:
    contents = json.loads(j.read())

questions = contents["stat_status_pairs"]
base_url = "https://leetcode.com/problems/"

mylist = []

idx = 1
for question in questions:
    question_name = question["stat"]["question__title"]
    difficulty = question["difficulty"]["level"]
    url = base_url + str(question["stat"]["question__title_slug"]) + "/"
    if question["paid_only"] == False:
        temp = {}
        temp["SL No"] = idx
        idx+=1
        temp["Question Name"] = question_name
        temp["Rating"] = difficulty
        if difficulty == 1:
            temp["Tag"] = "Easy"
        elif difficulty == 2:
            temp["Tag"] = "Medium"
        else:
            temp["Tag"] = "Hard"
        temp["URL"] = url
        temp["Solved"] = "Yes" if question["status"] == "ac" else "No"
        mylist.append(temp)


file = open('questions.json', 'w+')

json.dump(mylist, file)




