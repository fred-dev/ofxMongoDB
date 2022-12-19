# Introduction

ofxMongoDB is a wrapper for the c++ mongoDB driver made for openFrameworks.

Use at your own risk!!!


# Installation

Currently working with the OF Master Branch as at 19/12/2022, testing using Xcode 14.1 and Visual Studio 2019


Either clone out the source code using git:

    > cd openFrameworks/addons/
    > git clone https://github.com/fred-dev/ofxMongoDB.git
    
Or download the source from GitHub [here](https://github.com/fred-dev/ofxMongoDB.zip), unzip the folder, rename it from `ofxMongoDB-master` to `ofxMongoDB` and place it in your `openFrameworks/addons` folder.

To run the example, import it into the project generator, create a new project, and open the project file in your IDE.


# Working with ofxMongoDB

You will need a mongoDB database somewhere, it is pretty easy to use a cloud instance from here: [here](https://www.mongodb.com/cloud/atlas/)

If you dont have any data you can use a sample data set as outlined here: [here](https://www.mongodb.com/basics/sample-database)

If you are using a cloud databse make sure you allow for the IP you are using to have access to the database: [here](https://www.mongodb.com/docs/atlas/security/ip-access-list/)


# Functionality

Currently this addon can read and write to instances of mongoDB databases. Filtering is limited to a single paramater, but I will add the optin for custom queries shortly.



