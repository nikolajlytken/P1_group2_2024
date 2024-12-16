import pandas as pd

def import_csv(filename='paastiger_data.csv'):
    try:
        csv = pd.read_csv(f'{filename}', sep=';')
        print("CSV file loaded successfully")
        print("\nDataFrame Info:")
        print(csv.info())
        return csv
    except FileNotFoundError:
        print("Error: paastiger_data.csv file not found")
    except pd.errors.EmptyDataError:
        print("Error: CSV file is empty")
    except Exception as e:
        print(f"Error loading CSV: {e}")

def import_dataset():
    try: 
        with open("dataset.txt") as input:
            print("dataset loaded correctly")
            return [line.strip().split(',') for line in input]
    except FileNotFoundError:
        print("Error: dataset.txt file not found")
    except Exception as e:
        print(f"Error loading dataset: {e}")

def pandafilter(csv):
    csv['Total'] = pd.to_numeric(csv['Total'].str.replace('.', ''), errors='coerce').astype('Int64')
    f_csv = csv[csv['Stationsnavn'] != 'lokaltog']
    ff_csv = f_csv[f_csv['Total'] != '0']
    fff_csv = ff_csv.loc[:, ['Stationsnavn', 'Total']]
    return fff_csv

def createNewDataset(f_csv,dataset):
    for i,station in enumerate(dataset): 
        if station[0] in f_csv['Stationsnavn'].values:
            total = f_csv.loc[f_csv['Stationsnavn'] == station[0], 'Total'].values[0]
            dataset[i].insert(1,total)
    return dataset

def writeNewDataset(dataset):
        with open("newDataset.txt",'w') as outfile: 
            for line in dataset:
                for elm in line: 
                    outfile.write(str(elm))
                    outfile.write(',')
                outfile.write('\n')
        outfile.close()
        return "SUCCES"




def main():
    print("------ Import  csv ------\n")
    csv = import_csv()
    print("\n-------------------------")
    filtered_csv = pandafilter(csv)
    print("------ Printed csv ------")
    print(filtered_csv)
    print("\n-------------------------")
    print("------ Printed data ------")
    data = import_dataset()
    [print(line) for line in data]

    print("\n-------------------------")
    print("------ CreatingData ------")
    data = createNewDataset(filtered_csv,data)
    print(data)
    print("\n-------------------------")
    print("------ Writing Data ------")
    print(writeNewDataset(data))
    print("\n-------------------------")



if __name__ == "__main__": 
    main()