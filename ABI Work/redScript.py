import pandas as pd

# Read the two input CSV files
file1 = pd.read_csv('abi-1-failed-cases.csv')  # Replace with your first file's name
file2 = pd.read_csv('abi-0-failed-cases.csv')  # Replace with your second file's name

# Combine the data from both files and drop duplicates
combined_df = pd.concat([file1, file2]).drop_duplicates()

# Write the combined and de-duplicated data to a new CSV file
combined_df.to_csv('combined_result.csv', index=False)

print("Combined and de-duplicated data has been saved in 'combined_result.csv'")
