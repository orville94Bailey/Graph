#include "matrixgraph.h"
#include "listgraph.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>

int main()
{
    std::ifstream read_file;
    std::string file_name;

    std::cout<<"Enter the name of the file to examine: ";
    std::cin>>file_name;

    MatrixGraph DFA;

    read_file.open(file_name.c_str());

    if(read_file.is_open())
    {
        int temp;
        std::string current_line;

        //puts the final states into the final_states vector
        getline(read_file, current_line);
        //this for loop was found at "https://answers.yahoo.com/question/index?qid=20110614175714AAQb661"
        for(std::istringstream iss(current_line); iss>>temp; )
        {
            DFA.finalStates.push_back(temp);
        }
        //end of cited content

        int start_vertex, end_vertex;
        char input;
        //loop until no more data from here
        while(read_file.good())
        {
            //get first number...done
            //get input...done
            //get second number...done
            read_file>>start_vertex>>input>>end_vertex;
            //check if vertex 1 exists...done
            if(!DFA.findVertex(start_vertex))
            {
                //create if DNE...done
                DFA.addVertex(start_vertex);
            }
            //check if vertex 2 exists...done
            if(!DFA.findVertex(end_vertex))
            {
                //create if DNE...done
                DFA.addVertex(end_vertex);
            }
            //create directed weighted edge between them...done
            DFA.addEdgeDirected(start_vertex,end_vertex,input);
        }
    }
    else
    {
        std::cout<<"File name not found."<<std::endl;
        exit(2);
    }
    //get user input...done
    //DFA.printMatrix();  //debugging print
    std::string user_input;
    bool invalid_string;
    invalid_string = false;
    bool quit_flag;
    quit_flag = false;

    do
    {

        std::cout<<"Enter the string to check: ";
        std::cin>>user_input;

        //strip user_input of newline...done
        //newline stripping was found here: "http://stackoverflow.com/questions/1488775/c-remove-new-line-from-multiline-string"
        user_input.erase(std::remove(user_input.begin(), user_input.end(), '\n'), user_input.end());

        //BEGIN STRING CHECKING
        if(user_input=="quit")
        {
            std::cout<<"Rerun the checker to check another DFA"<<std::endl;
            break;
        }
        DFA.resetToBegining();
        invalid_string = false;
        for(int i = 0; i<user_input.size(); i++)
        {
            //std::cout<<"Transversed: "<<i<<std::endl;
            if(!DFA.transverseInput(user_input[i]))
            {
                std::cout<<"Failded transversal on iteration "<<i + 1<<std::endl;
                invalid_string = true;
                break;
            }
        }
        if(!invalid_string)
        {
            if(DFA.currentIsFinal())
            {
                std::cout<<"The string \""+ user_input +"\" is valid"<<std::endl;
            }
            else
            {
                std::cout<<"The string \""+ user_input +"\" is invalid"<<std::endl;
            }
        }
    }while(!quit_flag);




    /*
    srand(time(NULL));

    MatrixGraph test;
    test.addVertex(1);
    test.addVertex(2);
    test.addVertex(3);
    test.addVertex(4);
    test.addVertex(5);
    test.addVertex(6);
    test.addVertex(7);
    test.addVertex(8);
    test.addVertex(9);
    test.addVertex(10);

    test.addEdge(1,2,rand() % 20);
    test.addEdge(1,3,rand() % 20);
    test.addEdge(1,4,rand() % 20);
    test.addEdge(2,5,rand() % 20);
    test.addEdge(3,7,rand() % 20);
    test.addEdge(4,5,rand() % 20);
    test.addEdge(7,6,rand() % 20);
    test.addEdge(5,6,rand() % 20);
    test.addEdge(5,8,rand() % 20);
    test.addEdge(6,8,rand() % 20);
    test.addEdge(6,10,rand() % 20);
    test.addEdge(6,9,rand() % 20);
    test.addEdge(9,10,rand() % 20);
    test.addEdge(8,10,rand() % 20);

    std::cout << "Breadth first: " << std::endl;
    test.printBreadthFirst(0);

    std::cout << std::endl;

    std::cout << "Depth first:" << std::endl;
    test.printDepthFirst(0);

    std::cout << std::endl;
    std::vector<int> dijkstraPath = test.findDijkstraPath(8,2);

    std::cout << "Dijkstra path from " << 8 << " to " << 2 << ":" << std::endl;
    for(int i = 0; i < dijkstraPath.size(); i++)
    {
        std::cout << dijkstraPath.at(i) << std::endl;
    }

    std::cout << std::endl;

    std::vector<int> primPath = test.findPrimPath(8,2);

    std::cout << "Prim path from " << 8 << " to " << 2 << ":" << std::endl;
    for(int i = 0; i < primPath.size(); i++)
    {
        std::cout << primPath.at(i) << std::endl;
    }

    return 0;
    */
}
