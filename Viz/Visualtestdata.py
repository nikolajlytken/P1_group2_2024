import json
import os
import csv

trains_dict = {}
dataset_dict = {}

def load_data(file):
    with open(f"JourneyDetail_data/{file}",'r') as input:
        data = json.load(input)
        input.close()
        return data
    
def get_line_info(data):
    trainName = data["Product"][0]["name"]
    trains_dict[trainName] = {'stops':[],'coordinates':[]}
    for station in data["Stops"]["Stop"]:
        trains_dict[trainName]['stops'].append(station["name"])
        lon = station["lon"]
        lat = station["lat"]
        trains_dict[trainName]['coordinates'].append((lon,lat))


def write_dataset():
    with open("dataset.csv", 'w', newline='') as outfile:
        writer = csv.writer(outfile)
        for index,station in trains_dict['IC 152']['stops']:
            row = [station]
            
            writer.writerow(row)


def main():
    get_line_info(load_data('IC 152.json'))
    print(trains_dict)

if __name__ == '__main__':
    main()