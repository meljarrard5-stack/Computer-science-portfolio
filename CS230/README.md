# CS 230 Portfolio Reflection

### Briefly summarize The Gaming Room client and their software requirements. Who was the client? What type of software did they want you to design?

The Gaming Room was the client for this project. They already had a game called *Draw It or Lose It* that was originally created for Android, but they wanted to expand it so it could be used on other operating platforms. The game is based on teams trying to guess an image as it is gradually revealed. The software needed to support multiple games at the same time, with multiple teams and players in each game. It also needed to make sure that game, team, and player names were unique and that the application could work in a distributed environment.

### What did you do particularly well in developing this documentation?

One thing I think I did well was comparing the different operating systems and looking at the advantages and disadvantages of each one. I considered things such as memory management, storage, security, development tools, and how well each platform would support the application. I also tried to connect the technical information back to the actual needs of The Gaming Room instead of only explaining how each operating system worked.

### What about the process of working through a design document did you find helpful when developing the code?

Working through the design document was helpful because it made me think about how the application should be structured before getting too far into the code. Breaking the program down into classes and relationships made it easier to understand how the different parts would work together. The UML diagram was also useful because I could visually see the relationships between the game service, games, teams, and players. Planning these things ahead of time can make the coding process easier and help prevent problems later.

### If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?

If I could revise one part of my work, I would probably improve some of my platform recommendations. I would include more specific examples explaining why one platform would work better than another for this particular application. I would also try to make some of my explanations more concise while still including enough information to support my recommendation.

### How did you interpret the user's needs and implement them into your software design? Why is it so important to consider the user's needs when designing?

I interpreted the user's needs by first identifying the main requirements of the game and then deciding how those requirements could be handled in the software. For example, the client needed to support multiple games, teams, and players while also making sure duplicate names were not allowed. The design used things such as unique identifiers and the singleton design pattern to help meet those requirements. I also considered the client's goal of eventually supporting users on different operating systems when making recommendations for the server and overall architecture.

It is important to consider the user's needs because the software is being created to solve a problem for them. A program could technically work but still not be useful if it does not meet the client's actual requirements. Understanding the user's needs also helps developers avoid wasting time creating features that are unnecessary.

### How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?

My approach was to start by identifying the requirements and then break the system into smaller pieces. I looked at the classes that were needed, how they related to each other, and what design patterns could help organize the application. I also compared operating systems and considered areas such as security, memory, storage, networking, and scalability.

For a similar project in the future, I would use the same general process of understanding the requirements before starting development. I would use UML diagrams and other planning documents to organize the design, compare possible technologies, and think about scalability and security early in the process. Having a clear design before writing most of the code makes development easier and gives the development team something to reference throughout the project.
