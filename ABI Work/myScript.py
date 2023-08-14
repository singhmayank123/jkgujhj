import pandas as pd
import glob

# List of input CSV files
input_files = glob.glob("test*.csv")  # Update the path as needed

# List to store selected rows
selected_rows = []

# Loop through each input CSV file
for file in input_files:
    df = pd.read_csv(file)  # Read the CSV file
    failed_rows = df[df['Status'] == 'Failed']  # Select rows with "Failed" status
    selected_rows.append(failed_rows)  # Append selected rows to the list

# Concatenate selected rows from all files
result_df = pd.concat(selected_rows, ignore_index=True)

# Write the result to a new CSV file
result_df.to_csv("abi-1-failed-cases-new.csv", index=False)

print("Selected rows with 'Failed' status have been stored in 'failed_rows.csv'")
