import pandas as pd
import glob

# Read the x.csv file
x_df = pd.read_csv('abi-1-failed-cases.csv')

# List of input CSV files
input_files = [file for file in glob.glob("*.csv") if file != "abi-1-failed-cases.csv"]

# List to store selected rows
selected_rows = []

# Loop through each row of x.csv
for index, x_row in x_df.iterrows():
    name_to_search = x_row['Name']
    for file in input_files:
        df = pd.read_csv(file)  # Read the CSV file
        matching_rows = df[df['Name'] == name_to_search]
        if not matching_rows.empty and matching_rows.iloc[0]['Status'] == 'Passed':
            selected_rows.extend(matching_rows.to_dict('records'))

# Create a DataFrame from selected rows
result_df = pd.DataFrame(selected_rows)

# Write the result to a new CSV file
result_df.to_csv("passed_rows.csv", index=False)

print("Passed rows have been stored in 'passed_rows.csv'")
