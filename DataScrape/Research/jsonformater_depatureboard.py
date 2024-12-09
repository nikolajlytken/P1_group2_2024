import json

with open("response_data_departureBoard_2.json","r") as f:
    input = json.load(f)

# output = []
# for depature in input["Departure"]:
#     if depature["Product"][0]["icon"]["res"]=="prod_ic":
#         output.append(json.dumps(depature,indent=4))


# with open("formated_depatureboard.json","w") as out:
#     json.dump(output,out,indent=2)


with open("formated_depatureboard.json", "a") as outfile:
    for departure in input["Departure"]:
        if departure["Product"][0]["icon"]["res"] == "prod_ic":
            json.dump(departure, outfile,indent=2)
            outfile.write(',\n')