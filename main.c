#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for Patient and Doctor
typedef struct {
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
    char department[50]; 
    char appointmentDetails[100]; 
    char assignedDoctorName[50]; 
} Patient;

typedef struct {
    char name[50];
    char specialization[50];
    int experience;
    char department[50]; 
} Doctor;

// Function prototypes
void addPatient(Patient *patients, int *patientCount, Doctor *doctors, int doctorCount);
void addDoctor(Doctor *doctors, int *doctorCount);
void searchPatientByName(Patient *patients, int patientCount);
void searchDoctorByName(Doctor *doctors, int doctorCount);
void bookAppointment(Patient *patients, int patientCount, Doctor *doctors, int doctorCount);
void displayAppointmentDetails(Patient *patients, int patientCount);

int main() {
    Patient patients[50];
    Doctor doctors[10];
    int patientCount = 0;
    int doctorCount = 0;
    int choice;

    do {
        // Display menu
        printf("\n==== Welcome to the Healthcare Management System ====\n");
        printf("1. Add Patient\n");
        printf("2. Add Doctor\n");
        printf("3. Search Patient by Name\n");
        printf("4. Search Doctor by Name\n");
        printf("5. Book Appointment\n");
        printf("6. Display Appointment Details\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount, doctors, doctorCount);
                break;
            case 2:
                addDoctor(doctors, &doctorCount);
                break;
            case 3:
                searchPatientByName(patients, patientCount);
                break;
            case 4:
                searchDoctorByName(doctors, doctorCount);
                break;
            case 5:
                bookAppointment(patients, patientCount, doctors, doctorCount);
                break;
            case 6:
                displayAppointmentDetails(patients, patientCount);
                break;
            case 7:
                printf("Exiting System. Thank you! Have a lovely day\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to add a new patient
void addPatient(Patient *patients, int *patientCount, Doctor *doctors, int doctorCount) {
    printf("\n=== Add Patient ===\n");

    // Get patient details from the user
    printf("Enter patient name: ");
    scanf(" %[^\n]s", patients[*patientCount].name);
    printf("Enter patient age: ");
    scanf("%d", &patients[*patientCount].age);
    printf("Enter patient gender: ");
    scanf(" %[^\n]s", patients[*patientCount].gender);
    printf("Enter patient diagnosis: ");
    scanf(" %[^\n]s", patients[*patientCount].diagnosis);

    // Increment patient count
    (*patientCount)++;
}

// Function to add a new doctor
void addDoctor(Doctor *doctors, int *doctorCount) {
    printf("\n=== Add Doctor ===\n");

    // Get doctor details from the user
    printf("Enter doctor name: ");
    scanf(" %[^\n]s", doctors[*doctorCount].name);
    printf("Enter doctor specialization: ");
    scanf(" %[^\n]s", doctors[*doctorCount].specialization);
    printf("Enter doctor experience (in years): ");
    scanf("%d", &doctors[*doctorCount].experience);
    printf("Enter doctor department: ");
    scanf(" %[^\n]s", doctors[*doctorCount].department);

    // Increment doctor count
    (*doctorCount)++;
}

// Function to search for a patient by name
void searchPatientByName(Patient *patients, int patientCount) {
    char searchName[50];
    printf("\nEnter the name of the patient to search: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
	     // Display patient details
            printf("\n=== Patient Found ===\n");
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("Diagnosis: %s\n", patients[i].diagnosis);
            printf("Assigned Doctor: %s\n", patients[i].assignedDoctorName[0] != '\0' ? patients[i].assignedDoctorName : "Not assigned");
            printf("Department: %s\n", patients[i].department);
            printf("Appointment Details: %s\n", patients[i].appointmentDetails[0] != '\0' ? patients[i].appointmentDetails : "Not booked");
            return;
        }
    }

    printf("\nPatient with name '%s' not found.\n", searchName);
}

// Function to search for a doctor by name
void searchDoctorByName(Doctor *doctors, int doctorCount) {
    char searchName[50];
    printf("\nEnter the name of the doctor to search: ");
    scanf(" %[^\n]s", searchName);
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].name, searchName) == 0) {
	     // Display doctor details
            printf("\n=== Doctor Found ===\n");
            printf("Name: %s\n", doctors[i].name);
            printf("Specialization: %s\n", doctors[i].specialization);
            printf("Experience: %d years\n", doctors[i].experience);
            printf("Department: %s\n", doctors[i].department);
            return;
            }
        }

    printf("\nDoctor with name '%s' not found.\n", searchName);
}


// Function to display appointment details for a patient
void displayAppointmentDetails(Patient *patients, int patientCount) {
    char searchName[50];
    printf("\nEnter the name of the patient to display appointment details: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
	     // Display appointment details
            printf("\n=== Appointment Details ===\n");
            printf("Patient Name: %s\n", patients[i].name);
            printf("Assigned Doctor: %s\n", patients[i].assignedDoctorName[0] != '\0' ? patients[i].assignedDoctorName : "Not assigned");
            printf("DepartmeCardiologynt: %s\n", patients[i].department);
            printf("Appointment Details: %s\n", patients[i].appointmentDetails[0] != '\0' ? patients[i].appointmentDetails : "Not booked");
            return;
        }
    }

    printf("\nPatient with name '%s' not found.\n", searchName);
}

// Function to book an appointment for a patient
void bookAppointment(Patient *patients, int patientCount, Doctor *doctors, int doctorCount) {
    char searchName[50];
    printf("\nEnter the name of the patient to book an appointment: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].name, searchName) == 0) {
            // Check if the patient already has an assigned doctor
            if (patients[i].assignedDoctorName[0] != '\0') {
                printf("\nPatient '%s' already has an appointment with Doctor '%s'.\n", patients[i].name, patients[i].assignedDoctorName);
                return;
            }

            // Ask for the department to book the appointment
            printf("Enter the name of the department for appointment from the list below\n1. Cardiology\n2. Neurology\n3. Burn Unit\n4. Radiology\n5. Gynecology\n6. Urology\n7. Surgery\n ");
            scanf(" %[^\n]s", patients[i].department);

            // Display available doctors in the selected department
            printf("Available Doctors in the %s department:\n", patients[i].department);
            for (int j = 0; j < doctorCount; j++) {
                if (strcmp(doctors[j].department, patients[i].department) == 0) {
                    printf("%d. %s\n", j + 1, doctors[j].name);
                }
            }

            // Ask for the selected doctor
            int selectedDoctorIndex;
            printf("Select a doctor (enter the corresponding number): ");
            scanf("%d", &selectedDoctorIndex);

            // Validate the selected doctor
            if (selectedDoctorIndex >= 1 && selectedDoctorIndex <= doctorCount &&
                strcmp(doctors[selectedDoctorIndex - 1].department, patients[i].department) == 0) {
                // Assign the selected doctor to the patient
                strcpy(patients[i].assignedDoctorName, doctors[selectedDoctorIndex - 1].name);

                // Ask for appointment details
                printf("Enter appointment details: ");
                scanf(" %[^\n]s", patients[i].appointmentDetails);

                printf("\nAppointment booked successfully!\n");
            } else {
                printf("\nInvalid doctor selection. Appointment booking failed.\n");
            }

            return;
        }
    }

    // Patient not found
    printf("\nPatient with name '%s' not found.\n", searchName);
}
