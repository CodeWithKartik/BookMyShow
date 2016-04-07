# BookMyShow
A ticket booking utility: back end support only

Created by Kartik Srivastava. This project was undertaken by me as a leisure project to mimic
the ticket booking utility of bookmyshow.com
Here I only present the backend code. User may use this utility to
understand the overall ticket booking process.

Classes: 
1.) BookingMgr manages the entire ticket booking process
2.) LoginMgr manages the login procedure to the ticet booking portal. 
Members and Admin user's data is persisted using a separate utility:
Class: PersistentObjectUtility
3.) All the classes ending with database holds the actual pointers to the data pertaining to movies, cinema and users.
4.) Class Admin is provided with special privilages to modify certain databases. 
These privileges are judiciously provided via the use of friend functions.
