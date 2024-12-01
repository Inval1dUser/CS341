import random
def dataGenerator(iteration):
    #To generate the Child's First Name, choose a name randomly from your text file of first names.
    first_name = (str(random.choice(open("firstNames.txt").readlines()))).rstrip()
    #print(first_name)

    #To generate the Child's Last Name, choose a name randomly from your text file of last names.
    last_name = (str(random.choice(open("lastNames.txt").readlines()))).rstrip()
    #print(last_name)

    #To generate the Child's Date of Birth, generate a random month (between 1-12 inclusive), day (between 1-28 inclusive to keep things simple), and year (between 2006-2018 inclusive).
    random_month = random.randint(1, 12)
    random_day = random.randint(1, 28)
    
    if iteration % 10 == 0:
        # Every 10th birthdate in MM/DD/YYYY format
        random_year = random.randint(2006, 2018)
        birth_date = str(random_month) + "/" + str(random_day) + "/" + str(random_year)
    else:
        # MM/DD/YY format
        random_year = random.randint(6, 18)
        birth_date = str(random_month) + "/" + str(random_day) + "/" + str(random_year)

    

    def getBirthDate():
        return birth_date
    #print(birth_date)

    #To generate the Parent's First Name, choose a name randomly from your text file of first names. 
    parent_first_name = (random.choice(open("firstNames.txt").readlines())).rstrip()
    parent_last_name = last_name

    #To generate the Parent's Phone, generate random numbers.
    phone_number = str(random.randint(100, 999)) + "-" + str(random.randint(100, 999)) + "-" + str(random.randint(1000, 9999))
    #print(phone_number)

    dataStr = first_name + ", " + last_name + ", " + birth_date + ", " + parent_first_name + ", " + parent_last_name + ", " + phone_number
    return dataStr

def change_num(string):
    phone_num = string.split(', ')[5]
    numEnd = string.split('-')[2]
    newNum = numEnd.replace(numEnd[0] + numEnd[1] + numEnd[2] + numEnd[3], numEnd[0] + numEnd[1] + numEnd[2])
    return newNum


#function call in loop
for i in range(0, 900):
    f = open("data.txt", "a") #file is open

    if (i%50) == 0:
        string = dataGenerator(i).split()
        string[5] = string[5].replace(string[5].split('-')[2], change_num(dataGenerator(i))) #replace phone_num in string with this
        newString = string[0] + " " + string[1] + " " + string[2] + " " + string[3] + " " + string[4] + " " + string[5]
        f.writelines(newString+'\n')
        continue
        
    f.writelines(dataGenerator(i)+'\n') #write data to file
    f.close()


#duplicate 100 random lines
for i in range(0, 100):
    f = open("data.txt", "r") #file is open for reading
    randNum = random.randint(1, 900)
    insert = f.readlines()[randNum]
    f.close()

    fnew = open("data.txt", "a") #file is open for writing
    fnew.writelines(insert) #write data to file
    fnew.close()