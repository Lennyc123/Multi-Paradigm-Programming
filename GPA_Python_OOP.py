# Import pandas, numpy and python statistics module
import pandas as pd
import numpy as np
import statistics

# creation of class: Student
class Student(object):
    def __init__(self, name, results):
        self._name = name
        self.results = results

    # Get student Name and return value
    @property
    def name(self):
        return self._name
    
    # Getting the average of a students results
    @property
    def average_results(self):
        return round((sum(list(self.results.values())) / len(self.results)), 2)
    
    # Getting a students highest scoring module
    @property
    def highest_scoring_module(self):
        return ("Highest Scoring Module: {} {}%".format(max(self.results, key=self.results.get), self.results[max(self.results, key=self.results.get)]))
    
    # Getting a students lowest scoring module
    @property
    def lowest_scoring_module(self):
        return ("Lowest Scoring Module: {} {}%".format(min(self.results, key=self.results.get), self.results[min(self.results, key=self.results.get)]))
    
    # Standard deviation of a students results 
    @property
    def standard_deviation(self):
        st_dev = np.std(list(self.results.values()))
        standard_deviation = round(st_dev, 2) 
        return f"Standard deviation of results: {standard_deviation}"

    # Median value of a students results
    @property
    def median_result(self):
        res = statistics.median(self.results.values())
        return(f"Median of results is: {int(res)}")

    # Method to print students results (percentage) as a grade letter e.g., A, B C, etc.,
    @property
    def module_grade_letter(self):
        print("\nList of modules and grade achieved:")
        for i in self.results:
            print(i)
            print("Grade:", GradeStatistics.grade_letter(self.results[i]))
    
        
# creation of class: Student Registry
class StudentRegistry(object):
    # Store students in a dictionary
    def __init__(self):
        self._students = {}
    
    # New students contain name and results data
    def register(self, student_name, results):
        new_student = Student(student_name, results)
        self._students[new_student] = new_student
    
    # Returns a list containing a tuple for each key value pair
    def list_students(self):
        return list(self._students.items())

# creation of class: Academic Records
class AcademicRecords(object):
    def __init__(self):
        self.student_registry = StudentRegistry()
    
    # Loop to retrieve data for each student
    def full_academic_report(self):
        for student, _ in self.student_registry.list_students():
            self.get_student_report(student)

    # Call on created methods within the student class and print their results
    def get_student_report(self, student):
        print("")
        print(f"Student Name: {student.name}")
        print(f"Average percentage: {student.average_results}")
        print("GPA: ", GradeStatistics.calculate_gpa(student.average_results))
        print(student.highest_scoring_module)
        print(student.lowest_scoring_module)
        print(student.standard_deviation)
        print(student.median_result)
        print(GradeStatistics.next_GPA(student.average_results))
        return(student.module_grade_letter)
    
    # Read in values values from a CSV file
    # Store this information as a pandas dataframe
    def load_records(self):
        df = pd.read_csv("CTASample.csv")
        module_names = list(df.keys()[1:])
        # Store the information within the dataframe as a dictionary
        for student in df.values:
            results = {key: value for (key, value) in zip(module_names, list(student[1:]))}
            self.student_registry.register(student[0], results)

# Live mode a user can enter a set of marks and modules from the command line and have the program calculate the GPA.
# creation of class: Live Mode
class liveMode(object):
    def __init__(self):
        self.results = []
        self.modules = []
    
    def gpa_cal(self):
        print("--- In live-Mode main menu ---")
        print("* Please enter your result from each module in order to calculate your GPA *\n")

        # Prompt user for input
        moduleName = str(input("Enter Module Name: "))
        self.modules.append(moduleName)
        resultsGrade = float(input("Enter Your Result (Percentage): "))
        self.results.append(resultsGrade)

        # Option for students to enter more modules if required.
        while True:
            addModule = input("Do you wish to add more modules? (YES/NO) : ")

            if addModule == "YES" or addModule == "yes" or addModule == "Yes" or addModule == "y" or addModule == "Y":
                moduleName = str(input("Enter Module Name: "))
                self.modules.append(moduleName)

                resultsGrade = float(input("Enter Your Result (Percentage): "))
                self.results.append(resultsGrade)

            elif addModule == "NO" or addModule == "No" or addModule == "no" or addModule == "n" or addModule == "N":
                print("\nModules and results listed below")
                break

            elif addModule != "YES" or addModule != "yes" or addModule != "Yes" or addModule != "y" or addModule != "Y":
                print("Please enter a valid response")

        # print students module names and results, based on their input. 
        i = 0
        while i < len(self.modules):
            print(self.modules[i], self.results[i])
            i = i + 1
        
        # Calculate a students GPA score.
        average_results = round((sum(self.results)) / len(self.results))
        print("\nCalculated GPA value")
        print(GradeStatistics.calculate_gpa(average_results))

# Creation of a class: Menu
# menu: user interface.
class Menu(object):
    
    @classmethod
    def display_menu(self):
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

# Creation of a new class: Grade Statistics
class GradeStatistics(object):
    # Global Variables
    GRADE = ["A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"]
    GPA_VAL = [4.2, 4.0, 3.8, 3.2, 3.0, 2.8, 2.2, 2.0, 1.8, 1.2, 1.0, 0.8, 0.0]

    # Defining what GPA score is provided based on ones percentage.
    @classmethod
    def calculate_gpa(cls, student_average):
        if 90 <= student_average <= 100:
            return cls.GPA_VAL[0]
        elif 85 <= student_average <= 89:
            return cls.GPA_VAL[1]
        elif 80 <= student_average <= 84:
            return cls.GPA_VAL[2]
        elif 75 <= student_average <= 79:
            return cls.GPA_VAL[3]
        elif 70 <= student_average <= 74:
            return cls.GPA_VAL[4]
        elif 65 <= student_average <= 69:
            return cls.GPA_VAL[5]
        elif 60 <= student_average <= 64:
            return cls.GPA_VAL[6]
        elif 55 <= student_average <= 59:
            return cls.GPA_VAL[7]
        elif 50 <= student_average <= 54:
            return cls.GPA_VAL[8]
        elif 45 <= student_average <= 49:
            return cls.GPA_VAL[9]
        elif 40 <= student_average <= 44:
            return cls.GPA_VAL[10]
        elif 35 <= student_average <= 39:
            return cls.GPA_VAL[11]
        elif student_average <= 35:
            return cls.GPA_VAL[12]
    
    # How far from the next highest GPA a student was, if not at 4.2 
    # Calculating how far a student is from the next GPA
    @classmethod
    def next_GPA(cls, student_average):
        if 85 <= student_average <= 89:
            return ('{} % away from achieving a {} GPA'.format(round(90 - student_average, 2) ,cls.GPA_VAL[0]))
        elif 80 <= student_average <= 84:
            return ('{} % away from achieving a {} GPA'.format(round(85 - student_average, 2),cls.GPA_VAL[1]))
        elif 75 <= student_average <= 79:
            return ('{} % away from achieving a {} GPA'.format(round(80 - student_average, 2),cls.GPA_VAL[2]))
        elif 70 <= student_average <= 74:
            return ('{} % away from achieving a {} GPA'.format(round(75 - student_average, 2),cls.GPA_VAL[3]))
        elif 65 <= student_average <= 69:
            return ('{} % away from achieving a {} GPA'.format(round(70 - student_average, 2),cls.GPA_VAL[4]))
        elif 60 <= student_average <= 64:
            return ('{} % away from achieving a {} GPA'.format(round(65 - student_average, 2),cls.GPA_VAL[5]))
        elif 55 <= student_average <= 59:
            return ('{} % away from achieving a {} GPA'.format(round(60 - student_average, 2),cls.GPA_VAL[6]))
        elif 50 <= student_average <= 54:
            return ('{} % away from achieving a {} GPA'.format(round(55 - student_average, 2),cls.GPA_VAL[7]))
        elif 45 <= student_average <= 49:
            return ('{} % away from achieving a {} GPA'.format(round(50 - student_average, 2),cls.GPA_VAL[8]))
        elif 40 <= student_average <= 44:
            return ('{} % away from achieving a {} GPA'.format(round(45 - student_average, 2),cls.GPA_VAL[9]))
        elif 35 <= student_average <= 39:
            return ('{} % away from achieving a {} GPA'.format(round(40 - student_average, 2),cls.GPA_VAL[10]))
        elif student_average <= 35:
            return ('{} % away from achieving a {} GPA'.format(round(35 - student_average, 2),cls.GPA_VAL[11]))

# Defining what grade letter is provided based on ones percentage.
    @classmethod
    def grade_letter(cls, student_average):
        if 90 <= student_average <= 100:
            return cls.GRADE[0]
        elif 85 <= student_average <= 89:
            return cls.GRADE[1]     
        elif 80 <= student_average <= 84:
            return cls.GRADE[2]
        elif 75 <= student_average <= 79:
            return cls.GRADE[3]
        elif 70 <= student_average <= 74:
            return cls.GRADE[4]
        elif 65 <= student_average <= 69:
            return cls.GRADE[5]
        elif 60 <= student_average <= 64:
            return cls.GRADE[6]
        elif 55 <= student_average <= 59:
            return cls.GRADE[7]
        elif 50 <= student_average <= 54:
            return cls.GRADE[8]
        elif 45 <= student_average <= 49:
            return cls.GRADE[9]
        elif 40 <= student_average <= 44:
            return cls.GRADE[10]
        elif 35 <= student_average <= 39:
            return cls.GRADE[11]
        elif student_average <= 35:
            return cls.GRADE[12]

# Creation of a new class: Menu functionality            
# menu functionality
class main(object):
    while True:
        Menu.display_menu()
        print("")
        choice = input("Choice: ")

        if (choice == "5"):
            break
        elif (choice == "1"):
            academic_records = AcademicRecords()
            academic_records.load_records()
            academic_records.full_academic_report()
        elif (choice == "2"):
            live_Mode = liveMode()
            live_Mode.gpa_cal()

# Call main function
if __name__ == "__main__":
    main()