import os 
import json 
import math

printed_messages = set()
dir = "JourneyDetail_data"
files = os.listdir(dir)

trains_dict = {}
dataset_dict = {}
#loads a given json file. 
def load_data(file):
    with open(f"JourneyDetail_data/{file}",'r') as input:
        data = json.load(input)
        input.close()
        return data
    
# Prints trainName, first and last stops of all found trains.
def printstationslist(data):
        end = len(data["Stops"]["Stop"])-1
        first_stop = data["Stops"]["Stop"][0]["name"]
        last_stop = data["Stops"]["Stop"][end]["name"]
        trainName = data["Product"][0]["name"]
        message = f"{first_stop} -> {last_stop}"
        
        if message not in printed_messages:
            print(f"train: {trainName}",message)
            printed_messages.add(message)
        
def get_line_info(data):
    if data["Product"][0]["operator"] != "Skånetrafiken":
        trainName = data["Product"][0]["name"]
        trains_dict[trainName] = {'stops':[],'coordinates':[]}
        for station in data["Stops"]["Stop"]:
            cleaned_name = station["name"].replace(" st.", "").replace(" St.", "").strip()
            trains_dict[trainName]['stops'].append(cleaned_name)
            lon = station["lon"]
            lat = station["lat"]
            trains_dict[trainName]['coordinates'].append((lon,lat))

def create_dataset():
    """
    Creates the dataset from trains_dict

    dataset structure is defined as: 
        {stationName:{connectsTo[],DistBetween[]}}
    """
    for train in trains_dict:
        l = len(trains_dict[train]["stops"])
        for i in range(l-1):
            currSt = trains_dict[train]["stops"][i+1]
            currCoord = trains_dict[train]["coordinates"][i+1]

            prevSt = trains_dict[train]["stops"][i]
            prevCoord = trains_dict[train]["coordinates"][i]

            dist = calc_dist(currCoord,prevCoord)

            if prevSt in dataset_dict:
                if currSt in dataset_dict[prevSt]["connectsTo"]:
                    continue
                else:    
                    dataset_dict[prevSt]["connectsTo"].append(currSt)
                    dataset_dict[prevSt]["dist"].append(dist)
            else:    
                dataset_dict[prevSt] = {'connectsTo':[],'dist':[]}
                dataset_dict[prevSt]["connectsTo"].append(currSt)
                dataset_dict[prevSt]["dist"].append(dist)


    
# Add one connection to from source to input, with distance
# Next feature is to add which trainline is connecting them. 
def write_dataset():
    with open("dataset.txt",'w') as outfile:
        for station in dataset_dict:
            length = len(dataset_dict[station]["connectsTo"])
            outfile.write(station)
            outfile.write(",")
            for i in range(length):
                outfile.write(dataset_dict[station]["connectsTo"][i])
                outfile.write(",")
                outfile.write(str(dataset_dict[station]["dist"][i]))
                outfile.write(",")
            outfile.write("\n")
            missing = ['Varde','Struer','Nykøbing F','Hjørring']
            for station in missing:
                outfile.write(station,',','0')
    outfile.close()


# calculates distance between 2 sets of coordinates. 
def calc_dist(c1,c2):
        # Convert latitude and longitude from degrees to radians
    phi1 = math.radians(c1[1])
    phi2 = math.radians(c2[1])
    delta_phi = math.radians(c2[1] - c1[1])
    delta_lambda = math.radians(c2[0] - c1[0])

    # Haversine formula
    a = math.sin(delta_phi / 2)**2 + \
        math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2)**2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

    # Earth's radius in kilometers (use 3956 for miles)
    radius = 6371.0

    # Calculate the distance
    distance = radius * c

    return "{:.3f}".format(distance)

def main():
    dir = "JourneyDetail_data"
    files = os.listdir(dir)

    for file in files:
    #file = "IC 152.json"
        print(f"________ loading {file} __________" )
        get_line_info(load_data(file))
        print("succesful load of data")

    for train in trains_dict:
        print(f"________ {train} __________" )

        length = len(trains_dict[train]['stops'])
        for i in range(length):
            print("station: ", trains_dict[train]["stops"][i],"Coordinates: ", trains_dict[train]["coordinates"][i])
    
    print("________ Creating dataset________")
    create_dataset()
    print("Created dataset")

    print("________ Writing dataset________")
    write_dataset()

if __name__ == '__main__':
    main()