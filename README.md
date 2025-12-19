# CS210.Week8
Final assignment for my C++ class, which emphasized readability and industry best practices in my coding process.

Project Summary: This project tested my file stream technique by having me process a data file and synthesizing different information visualization outputs. The incoming data was simpler than a CSV file format, but it primed me for the data logic necessaray for outputting information at scale.

Problem Solved: I designed a single-pass file reader that constructs a local dictionary for quick access to word frequency data. Before manipulating the data, the snapshot of the incoming file data is saved to an external file which is then closed. This is a heavily front-loaded method for compiling data, but it makes retrieval computationally lightweigh during user runtime.

What I Did Well: I'm proud of the low processing cost of my final program. Also, the data output methods simply built on top of each other without being explicitly polymorphic. I feel like my coding process was remarkably efficient.

What Could I Do Better: My histogram is misaligned due to irregular word lengths. I should have included a function that tracks the longest string within the dictionary keys and used that value to setwidth(longestWord) before outputting tallies. Also, an option to reset and repopulate my local dictionary with the backup file (read-only and one-way) would have been useful.

Difficulties: I wasted a lot of time before settling on the key:value solution. I played with local variables to keep track of what words my program had already read over the course of multiple passes, which then evolved into an array, which then evolved into a dictionary to keep track of frequencies at a local level. All of this contemplation occurred at the pseudocode level, which made it so much easier to scrap and refactor my approach.

Transferable Skills: This particular project gives me confidence to set up a CRUD that can populate from a database. The data flow lends itself to additional modification without dramatic overhaul. An array list would be more appropriate at scale for this, however.

Maintainability: I included in line comments, kept relevant functions clustered together, and used proper naming conventions. The dictionary is modular and lends itself to modification or even abolishment.
