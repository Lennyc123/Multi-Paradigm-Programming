# Import pandas, numpy and python statistics module.
import pandas as pd
import numpy as np
import statistics

# Read in the values from the CSV i.e., student records.
# Store this information as a pandas dataframe
df = pd.read_csv("CTASample.csv")

# Global Variables
grade = ["A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"]
gpaVal = [4.2, 4.0, 3.8, 3.2, 3.0, 2.8, 2.2, 2.0, 1.8, 1.2, 1.0, 0.8, 0.0]
moduleNames = ["Intro to Programming", "Databases", "Computer Architecture", "Ethics in Computer Science",  "Advanced Programming", "Puzzles and Problem Solving"]

# Defining what grade letter is provided based on ones percentage.
def gradeLetter(percentR):
    if 90 <= percentR <= 100:
        gradeR = grade[0]
        print("Grade:", gradeR)
        
    elif 85 <= percentR <= 89:
        gradeR = grade[1]
        print("Grade:", gradeR)     

    elif 80 <= percentR <= 84:
        gradeR = grade[2]
        print("Grade:", gradeR)
        
    elif 75 <= percentR <= 79:
        gradeR = grade[3]
        print("Grade:", gradeR)
        
    elif 70 <= percentR <= 74:
        gradeR = grade[4]
        print("Grade:", gradeR)

    elif 65 <= percentR <= 69:
        gradeR = grade[5]
        print("Grade:", gradeR)
        
    elif 60 <= percentR <= 64:
        gradeR = grade[6]
        print("Grade:", gradeR)

    elif 55 <= percentR <= 59:
        gradeR = grade[7]
        print("Grade:", gradeR)
        
    elif 50 <= percentR <= 54:
        gradeR = grade[8]
        print("Grade:", gradeR)

    elif 45 <= percentR <= 49:
        gradeR = grade[9]
        print("Grade:", gradeR)
        
    elif 40 <= percentR <= 44:
        gradeR = grade[10]
        print("Grade:", gradeR)

    elif 35 <= percentR <= 39:
        gradeR = grade[11]
        print("Grade:", gradeR)
        
    elif percentR <= 35:
        gradeR = grade[12]
        print("Grade:", gradeR)

# Defining what GPA score is provided based on ones percentage.
def gpaCal(percentR):
    if 90 <= percentR <= 100:
        gpaR = gpaVal[0]
        print("GPA:", gpaR)
        
    elif 85 <= percentR <= 89:
        gpaR = gpaVal[1]
        print("GPA:", gpaR)
        
    elif 80 <= percentR <= 84:
        gpaR = gpaVal[2]
        print("GPA:", gpaR)
        
    elif 75 <= percentR <= 79:
        gpaR = gpaVal[3]
        print("GPA:", gpaR)
        
    elif 70 <= percentR <= 74:
        gpaR = gpaVal[4]
        print("GPA:", gpaR)

    elif 65 <= percentR <= 69:
        gpaR = gpaVal[5]
        print("GPA:", gpaR)
        
    elif 60 <= percentR <= 64:
        gpaR = gpaVal[6]
        print("GPA:", gpaR)

    elif 55 <= percentR <= 59:
        gpaR = gpaVal[7]
        print("GPA:", gpaR)
        
    elif 50 <= percentR <= 54:
        gpaR = gpaVal[8]
        print("GPA:", gpaR)

    elif 45 <= percentR <= 49:
        gpaR = gpaVal[9]
        print("GPA:", gpaR)
        
    elif 40 <= percentR <= 44:
        gpaR = gpaVal[10]
        print("GPA:", gpaR)

    elif 35 <= percentR <= 39:
        gpaR = gpaVal[11]
        print("GPA:", gpaR)
        
    elif percentR <= 35:
        gpaR = gpaVal[12]
        print("GPA:", gpaR)

# Getting the average of a students results and converting their average to a gpa score.
def studentGPA(i):
    results = []
    for m in (moduleNames):
        results.append(df[m][i])
    
    print("\nStudent Name: ", df['Student Name'][i])

    averageR = sum(results) / len(results)
    print("Average percentage: ", round(averageR, 2))
    gpaCal(averageR)

# Getting a students highest scoring module
def highestScoringModule(i):
    results = []
    for m in (moduleNames):
            results.append(df[m][i])
    
    highR = max(results)
    resultIndex = results.index(highR)
    print("Highest Scoring Module: ", moduleNames[resultIndex], highR,"%")

# Getting a students lowest scoring module
def lowestScoringModule(i):
    results = []
    for m in (moduleNames):
            results.append(df[m][i])

    lowR = min(results)
    resultIndex = results.index(lowR)
    print("Lowest Scoring Module: ", moduleNames[resultIndex], lowR, "%" )

# Standard deviation of a students results    
def standardDeviation(i):
    results = []
    for m in (moduleNames):
            results.append(df[m][i])
    
    st_dev = np.std(results)
    standard_deviation = round(st_dev, 2)
    print(f"Standard deviation of results: {standard_deviation}")

# Median value of a students results 
def medianResult(i):
    results = []
    for m in (moduleNames):
            results.append(df[m][i])

    res = statistics.median(results)
    print(f"Median of results is: {int(res)}")

# How far from the next highest GPA a student was, if not at 4.2 
def nextGPA(i):
    results = []
    for m in (moduleNames):
            results.append(df[m][i])
    
    averageR = sum(results) / len(results)
    
    if 85 <= averageR <= 89:
        print(round(90 - averageR, 2),"%", "away from achieving a", gpaVal[0], "GPA")

    elif 80 <= averageR <= 84:
        print(round(85 - averageR, 2),"%", "away from achieving a", gpaVal[1], "GPA")

    elif 75 <= averageR <= 79:
        print(round(80 - averageR, 2),"%", "away from achieving a", gpaVal[2], "GPA")

    elif 70 <= averageR <= 74:
        print(round(75 - averageR, 2),"%", "away from achieving a", gpaVal[3], "GPA")

    elif 65 <= averageR <= 69:
        print(round(70 - averageR, 2),"%", "away from achieving a", gpaVal[4], "GPA")

    elif 60 <= averageR <= 64:
        print(round(65 - averageR, 2),"%", "away from achieving a", gpaVal[5], "GPA")

    elif 55 <= averageR <= 59:
        print(round(60 - averageR, 2),"%", "away from achieving a", gpaVal[6], "GPA")

    elif 50 <= averageR <= 54:
        print(round(55 - averageR, 2),"%", "away from achieving a", gpaVal[7], "GPA")

    elif 45 <= averageR <= 49:
        print(round(50 - averageR, 2),"%", "away from achieving a", gpaVal[8], "GPA")

    elif 40 <= averageR <= 44:
        print(round(45 - averageR, 2),"%", "away from achieving a", gpaVal[9], "GPA")

    elif 35 <= averageR <= 39:
        print(round(40 - averageR, 2),"%", "away from achieving a", gpaVal[10], "GPA")

    elif averageR <= 35:
        print(round(35 - averageR, 2),"%", "away from achieving a", gpaVal[11], "GPA")

# Representing students results (percentage) as a grade letter i.e., A, B, C etc.,   
def moduleGradeLetter(i):
    print("\nList of modules and grade achieved:")    
    for m in moduleNames:
        print(m)
        gradeLetter(df[m][i])

# Live mode a user can enter a set of marks and modules from the command line and have the program calculate their GPA.
def liveMode():
    modules = []
    results = []
    print("--- In live-Mode main menu ---")
    print("* Please enter your result from each module in order to calculate your GPA *\n")
    
    # Prompt user for input
    moduleName = str(input("Enter Module Name: "))
    modules.append(moduleName)
    resultsGrade = float(input("Enter Your Result (Percentage): "))
    results.append(resultsGrade)

    # Option for students to enter more modules if required.
    while True:
        addModule = input("Do you wish to add more modules? (YES/NO) : ")

        if addModule == "YES" or addModule == "yes" or addModule == "Yes" or addModule == "y" or addModule == "Y":
            moduleName = str(input("Enter Module Name: "))
            modules.append(moduleName)

            resultsGrade = float(input("Enter Your Result (Percentage): "))
            results.append(resultsGrade)

        elif addModule == "NO" or addModule == "No" or addModule == "no" or addModule == "n" or addModule == "N":
            print("\nModules and results listed below")
            break

        elif addModule != "YES" or addModule != "yes" or addModule != "Yes" or addModule != "y" or addModule != "Y":
            print("Please enter a valid response")
            
    # print students module names and results, based on their input.        
    i = 0
    while i < len(modules):
        print(modules[i], results[i])
        i = i + 1
    
    # Calculate a students GPA score.
    averageR = sum(results) / len(results)
    print("\nCalculated GPA value")
    gpaCal(averageR)

# While loop to iterate through the csv file
# Call functions for each students i.e., i
def studentData():
    i = 0
    while i < len(df):
        studentGPA(i)
        highestScoringModule(i)
        lowestScoringModule(i)
        standardDeviation(i)
        medianResult(i)
        nextGPA(i)
        moduleGradeLetter(i)
        i = i + 1

# menu: user interface.
def display_menu():
    print("")
    var1 = ("Academic Records")
    print(var1)
    print("-" * len(var1))
    var2 = ("Welcome to the Main Menu")
    print(var2)
    print("-" * len(var2), "\n")
    print("1 - View student academic reports")
    print("2 - Enter Live-Mode (GPA Calculator)")
    print("5 - Exit application")

# menu functionality
def main():
    while True:
        display_menu()
        print("")
        choice = input("Choice: ")

        if (choice == "5"):
            break
        elif (choice == "1"):
            studentData()
        elif (choice == "2"):
            liveMode()

# Call main function
if __name__ == "__main__":
    main()