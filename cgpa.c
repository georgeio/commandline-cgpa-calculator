#include <stdio.h>
#include <stdlib.h>

double convert_score_to_grade(double*);

int main(int argc, char const *argv[])
{
	int total_courses = 0;
	int total_units = 0;
	double total_grades = 0;

	puts("[+] - Welcome to CGPA Calculator App:");
	printf("How many courses are you calculating CGPA for? ");
	fscanf(stdin, "%d", &total_courses);

	for (int i = 0; i < total_courses; ++i)
	{
		double tmp_crs_score; 
		int tmp_crs_unit, tmp_crs_grade;
		printf("[+] -- Course %d: \n", i+1);

		printf("\tEnter Course Credit: ");
		fscanf(stdin, "%d", &tmp_crs_unit);

		if( tmp_crs_unit > 5 || tmp_crs_unit < 1 ) {
			perror("Wrong course credit entered. Credit should be between 1-5");
			exit(0);
		}
			
		printf("\tEnter Course Score: ");
		fscanf(stdin, "%lg", &tmp_crs_score);

		if( tmp_crs_unit > 5 || tmp_crs_unit < 1 ) {
			perror("Wrong course credit entered. Credit should be between 1-5");
			exit(0);
		}

		total_grades += (convert_score_to_grade(&tmp_crs_score) * tmp_crs_unit);
		total_units += tmp_crs_unit;
	}

	printf("CGPA Calculated for a total of %d courses.\n", total_courses);
	printf("CGPA == %.2g\n", (total_grades / total_units));

	return 0;
}

double convert_score_to_grade(double* score_pt)
{
	int score = *score_pt;
	double grade = 0;

	if(score > 70)
		grade = 5;

	if(score >= 60 && score < 70)
		grade = 4;

	if(score >= 50 && score < 60)
		grade = 3;

	if(score >= 40 && score < 50)
		grade = 2;

	if(score >= 30 && score < 40)
		grade = 1;

	return grade;
}