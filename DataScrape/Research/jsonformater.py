import json

with open('response_data_datainfo.json', ) as input_json:
    input_dict =json.load(input_json)



print("first item in input: ",input_dict["Line"][0]["Product"]["icon"]["res"])

for item in input_dict["Product"]:
    if item["Product"]["icon"]["res"] == "prod_ic":
        print(item)

# Transform python object back into json
# output_json = json.dumps(filtered_dict)


# # Write the formatted and filtered JSON data to a new file
# with open('filtered_output.json', 'w') as file:
#     json.dump(output_json, file, indent=4)

# print("Filtered and formatted JSON data written to filtered_output.json")
