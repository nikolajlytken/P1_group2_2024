import os 
import json 
import math

printed_messages = set()
#loads a given json file. 
def load_data(file):
    with open(f"JourneyDetail_data/{file}",'r') as input:
        data = json.load(input)
        input.close()
        return data
def printstationslist(data):
        end = len(data["Stops"]["Stop"])-1
        first_stop = data["Stops"]["Stop"][0]["name"]
        last_stop = data["Stops"]["Stop"][end]["name"]
        trainName = data["Product"][0]["name"]
        message = f"{first_stop} -> {last_stop}"
        
        if message not in printed_messages:
            print(f"train: {trainName}",message)
            printed_messages.add(message)
        
    
# Finds line in dataset containing the right starting station. 
def search_dataset():
    print("not done")

# Add one connection to from source to input, with distance
# Next feature is to add which trainline is connecting them. 
def add_to_stationline():
    print("not done")

# calculates distance between 2 sets of coordinates. 
def calc_dist(lat1,lon1,lat2,lon2):
        # Convert latitude and longitude from degrees to radians
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)

    # Haversine formula
    a = math.sin(delta_phi / 2)**2 + \
        math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2)**2

    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

    # Earth's radius in kilometers (use 3956 for miles)
    radius = 6371.0

    # Calculate the distance
    distance = radius * c

    return distance

def main():
    dir = "JourneyDetail_data"
    files = os.listdir(dir)

    for file in files: 
        printstationslist(load_data(file))


if __name__ == '__main__':
    main()