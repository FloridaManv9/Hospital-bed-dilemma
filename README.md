# Hospital-bed-dilemma
Sadly, the Covid-19 pandemic has gotten even more out-of-hand in the state of Florida. As more and 
more people have become sick, more and more people have become sick enough to seek out 
hospitalization. This is starting to become a serious problem for the hospitals who are not sure if they 
are going to have beds for all of these Covid-19 patients. 
Tampa General Hospital is affiliated with the USF School of Medicine and they have come to USF to ask 
for help in trying to manage the onslaught of patents that they believe that they will be receiving. The 
programmers who would normally handle this task are currently busy trying to solve vaccine supply 
chain problems. Once again what this means is that the responsibility of creating the program that 
Tampa General needs falls on you. 
Tampa General has decided that all of their Covid-19 patients will be placed in their Tower A building. 
This building can handle 10 patients per floor and is ten stories tall. Tampa General is planning on taking 
all of their current Covid-19 patients, they have 100, and loading them into Tower A. Once they have 
done this, they want to conduct an experiment: should they move Covid-19 patients on the upper floors 
to lower floors when beds become available in order to reduce the distance that nurses and doctors 
have to travel to see patient? 
This means that your program will have to be configurable to run in two different modes: the first is one 
where patients just go home and their bed frees up. The statistics will be reported on how the hospital 
looks when this happens. 
The second is when as the Covid-19 patients get better and go home (hopefully) beds will free up. What 
the hospital wants to do is to move Covid-19 patients who are on the top floors to lower floors when 
space frees up. When a floor has been completely cleared of Covid-19 patients, then that floor can be 
used for regular patients at the hospital. A floor is either completely Covid-19 or completely non-Covid-
19. 
You need to create a C program that will use patient data to initially load Tower A. Then in the first 
scenario patients will just go home and in the second scenario as patients start to go home, you will 
move patients from the top floors to lower floors. When a floor has been completely cleared of Covid-19 
patients, you'll mark that floor as being a Non-Covid-19 floor. You will do this until all of the Covid-19 
patients have left. Every time 10 patients have gone home you will print out the current status of each 
 
hospital bed (M/F or "." for empty). You will also print out the number of Tower A floors that are Covid-
19 floors and the number that are Non-Covid-19 floors. 
You are permitted to encode a flag into your program to let it know if it is running scenario 1 or scenario 
2. 
 
Sample Data Set: 
The data file that you will be provided with will contain data in the following format:  
sex, recuperation time 
 
Assignment Requirements: 
 
1. Load Tower A with the 100 Covid-19 patients who are currently in the hospital. 
 
2. Find a room to place them in at the hospital. Record their sex. Start a timer for when they will be 
released. 
 
3. Every time that you clear another floor of Covid-19 patients you'll print out the following 
statistics: 
• Number of Covid - 19 patients 
• Number of empty beds 
• Number of Covid-19 floors 
• Number of Non-Covid-19 floors 
 
4. If a Covid-19 floor empties out, then mark it as being a non-Covid-19 floor.  
 
5. In scenario #2: manage the beds and try to clear out floors: when somebody goes home, try to 
move someone from a higher floor into their spot in order to clear out a floor. 
 
6. Your code must contain the following comment header: 
/* 
 * COP 3515 – Fall Semester, 2020 
 * 
 * Homework #2: The Hospital Bed Problem 
 * 
 * (Your Name) 
 * 
 */ 
