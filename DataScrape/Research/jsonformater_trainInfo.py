import json

with open('response_data_trainSearch_2.json', ) as input_json:
    input_dict =json.load(input_json)

station_counts = dict()

# Iterate through the journey details and stops
for journey in input_dict["JourneyDetail"]:
    for stop in journey["Stops"]["Stop"]:
        station_name = stop["name"]
        # Increment count for each station
        if station_name in station_counts:
            station_counts[station_name] += 1
        else:
            station_counts[station_name] = 1

# Print the dictionary in a readable format
for station, count in station_counts.items():
    print(f"Station: {station}, Count: {count}")

# Alternative: print entire dictionary at once
print("\nFull dictionary:")
print(json.dumps(station_counts, indent=4))
