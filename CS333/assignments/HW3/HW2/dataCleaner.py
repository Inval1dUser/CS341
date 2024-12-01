# Read data from data.txt
with open("data.txt", "r") as f:
    data_lines = [line.strip() for line in f]

# Part 2: Analyze data before cleaning
unique_lines = set()
duplicates = 0
four_digit_years = 0
missing_phone_numbers = 0

for line in data_lines:
    if line in unique_lines:
        duplicates += 1
    else:
        unique_lines.add(line)
    fields = line.split(", ")
    if len(fields) != 6:
        continue
    # Check for four-digit years
    birth_date = fields[2]
    year_part = birth_date.split("/")[-1]
    if len(year_part) == 4:
        four_digit_years += 1
    # Check for missing phone numbers
    phone_number = fields[5]
    digits_only = phone_number.replace("-", "")
    if len(digits_only) < 10:
        missing_phone_numbers += 1

print("Before cleaning:")
print("Number of records that have four-digit years:", four_digit_years)
print("Number of records that have missing data in the phone number:", missing_phone_numbers)
print("Number of records that are duplicated:", duplicates)

# Part 3: Clean data
cleaned_lines = []
unique_cleaned_lines = set()

for line in data_lines:
    fields = line.split(", ")
    if len(fields) != 6:
        continue
    # Fix birth dates with four-digit years
    date_parts = fields[2].split("/")
    if len(date_parts[2]) == 4:
        date_parts[2] = date_parts[2][2:]  # Convert to two-digit year
        fields[2] = "/".join(date_parts)
    # Replace missing phone numbers
    phone_number = fields[5]
    digits_only = phone_number.replace("-", "")
    if len(digits_only) < 10:
        fields[5] = "000-000-0000"
    # Remove duplicates
    cleaned_line = ", ".join(fields)
    if cleaned_line not in unique_cleaned_lines:
        unique_cleaned_lines.add(cleaned_line)
        cleaned_lines.append(cleaned_line)

# Write cleaned data back to data.txt
with open("data.txt", "w") as f:
    for line in cleaned_lines:
        f.write(line + '\n')

# Part 4: Analyze data after cleaning
four_digit_years = 0
missing_phone_numbers = 0
duplicates = 0  # Should be zero after cleaning

for line in cleaned_lines:
    fields = line.split(", ")
    if len(fields) != 6:
        continue
    # Check for four-digit years
    birth_date = fields[2]
    year_part = birth_date.split("/")[-1]
    if len(year_part) == 4:
        four_digit_years += 1
    # Check for missing phone numbers
    if fields[5] == "000-000-0000":
        missing_phone_numbers += 1

print("\nAfter cleaning:")
print("Number of records that have four-digit years:", four_digit_years)
print("Number of records that have missing data in the phone number:", missing_phone_numbers)
print("Number of records that are duplicated:", duplicates)
