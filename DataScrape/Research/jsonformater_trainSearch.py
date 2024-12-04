import json

with open('response_data_trainSearch.json', ) as input_json:
    input_dict =json.load(input_json)

for item in input_dict["JourneyDetail"]:
    for stop in item["Stops"]["Stop"]:
        print(stop["name"])
# Transform python object back into json
# output_json = json.dumps(filtered_dict)


# # Write the formatted and filtered JSON data to a new file
# with open('filtered_output.json', 'w') as file:
#     json.dump(output_json, file, indent=4)

# print("Filtered and formatted JSON data written to filtered_output.json")
