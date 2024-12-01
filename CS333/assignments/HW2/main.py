import random
def dataGenerator():
    #To generate the Child's First Name, choose a name randomly from your text file of first names.
    first_name = (str(random.choice(open("firstNames.txt").readlines()))).rstrip()
    #print(first_name)

    #To generate the Child's Last Name, choose a name randomly from your text file of last names.
    last_name = (str(random.choice(open("lastNames.txt").readlines()))).rstrip()
    #print(last_name)

    #To generate the Child's Date of Birth, generate a random month (between 1-12 inclusive), day (between 1-28 inclusive to keep things simple), and year (between 2006-2018 inclusive).
    random_month = random.randint(1, 12)
    random_day = random.randint(1, 28)
    random_year = random.randint(06, 18)

    #birth month
    birth_date = str(random_month) + "/" + str(random_day) + "/" + str(random_year)
    #print(birth_date)

    #To generate the Parent's First Name, choose a name randomly from your text file of first names. 
    parent_first_name = (random.choice(open("firstNames.txt").readlines())).rstrip()
    parent_last_name = last_name

    #To generate the Parent's Phone, generate random numbers.
    phone_number = str(random.randint(100, 999)) + "-" + str(random.randint(100, 999)) + "-" + str(random.randint(1000, 9999))
    #print(phone_number)

    dataStr = first_name + ", " + last_name + ", " + birth_date + ", " + parent_first_name + ", " + parent_last_name + ", " + phone_number
    return dataStr

#function call in loop
for i in range(0, 100):
    open("data.txt", "a")

    f = open("data.txt", "a") #file is open
    f.writelines(dataGenerator()+'\n') #write data to file
    f.close()



