/*

	stod---> string to double




*/




#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>



int main()
{

		//DECLARATIONS
	const int colWidth = 10,
			hr = 55; //horizontal rouler

	int election, counter;
	char again;//to use in the do while to repeat the program again y/n
	bool error=false;
	double lowest, highest = 0,
		openSum, openAvg,
		highSum, highAvg,
		lowSum , lowAvg,
		closeSum, closeAvg;

	//to store the date with the highest and lowest
	std::string cmpnyName, date, open, high, low, close, lowestDate, highestDate;
	std::ifstream inputFile;

		//program bucle
	do
	{
		//restablish variables every time the program starts again
		counter = 1;
		lowest = 99999.00, highest = 0,
			openSum = 0, openAvg = 0,
			highSum = 0, highAvg = 0,
			lowSum = 0, lowAvg = 0,
			closeSum = 0, closeAvg = 0;
		//declare ifstream object instance

			//choice bucle


			//promting the user to select an option from the menu
			std::cout << "Welcome to Stock Data Analyzer" << std::endl;
			std::cout << "Please choose from the following options" << std::endl;
			std::cout << "1. Apple\n"
				<< "2. IBM\n"
				<< "3. Facebook\n"
				<< "4. Netflix\n"
				<< "5. Microsoft\n";


		do
		{
			//if error occurs set error to false again
			error = false;
			std::cout<< "Your choice: ";

			//store election
			std::cin >> election;
			std::cout << std::endl;

			switch (election)
			{
			case 1://open apple file
				inputFile.open("AAPL.csv");
				cmpnyName = "Apple";
				break;
			case 2://open IBM file
				inputFile.open("IBM.csv");
				cmpnyName = "International Business Machines";
				break;
			case 3://open Facebook file
				inputFile.open("FB.csv");
				cmpnyName = "Facebook";
				break;
			case 4://open Netflix file
				inputFile.open("NFLX.csv");
				cmpnyName = "Netflix";
				break;
			case 5://open Microsoft file
				inputFile.open("MSFT.csv");
				cmpnyName = "Microsoft";
				break;
			default:
				//error
				if (std::cin.fail())
				{
					std::cout << "Wrong data type! Please enter numeric input only." << std::endl;
					error = true;
				}
				//range error
				else if (election < 1 || election > 5)
				{
					std::cout << "Please choose 1,2,3,4, or 5 only" << std::endl;
					std::cout << "Welcome to Stock Data Analyzer" << std::endl;
					std::cout << "Please choose from the following options" << std::endl;
					std::cout << "1. Apple\n"
						<< "2. IBM\n"
						<< "3. Facebook\n"
						<< "4. Netflix\n"
						<< "5. Microsoft\n";
					error = true;
				}
				break;
			}

			//clean the buffer
			std::cin.clear();
			std::cin.ignore(100, '\n');


			//while the user introduce not valid number repeat
		} while (error);

		//if open file fails program close
		if (!inputFile)
		{
			std::cout << "File not found. Exiting..." << std::endl;
			exit(EXIT_SUCCESS);
		}

		// read file until the end

		while (!inputFile.eof())
		{
			//store each section in its variable
			getline(inputFile, date, ',');
			getline(inputFile, open, ',');
			getline(inputFile, high, ',');
			getline(inputFile, low, ',');
			getline(inputFile, close, '\n');

			//find the highest value and its date
			if (std::stod(high.c_str()) > highest)
			{
				highest = std::stod(high.c_str());
				highestDate = date;
			}

			//find the lowest value and its date
			if (std::stod(low.c_str()) < lowest)
			{
				lowest = std::stod(low.c_str());
				lowestDate = date;
			}

			//add to the total each variable changed from string to double
			openSum += std::stod(open.c_str());
			highSum += std::stod(high.c_str());
			lowSum += std::stod(low.c_str());
			closeSum += std::stod(close.c_str());

			//increment the counter in each iteration of the loop
			counter++;


		}


		//find average diving the totals and the counter
		openAvg = openSum / counter;
		highAvg = highSum / counter;
		lowAvg = lowSum / counter;
		closeAvg = closeSum / counter;



		//-----------------------------------------------------------------------------//
		//OUTPUT


		//draw dashed line
		std::cout << std::internal;
		for (int i = 0; i < hr; i++)
		{
			std::cout << "_";
		}
		std::cout << std::endl;

		//defines alignment
		std::cout << std::right;

		//print name of the company
		std::cout << std::setw(30) << cmpnyName;

		std::cout << std::endl;

		//draw dashed line
		for (int i = 0; i < hr; i++)
		{
			std::cout << "_";
		}

		std::cout << std::endl;

		//Header row
		std::cout << std::left;
		std::cout << std::setw(5) << "Days"
			<< std::setw(colWidth) << "Avg-O"
			<< std::setw(colWidth) << "Avg-H"
			<< std::setw(colWidth) << "Avg-L"
			<< std::setw(colWidth) << "Avg-C" <<std::endl;

		//data row
		std::cout << std::fixed;//places after the '.' always the same
		std::cout << std::setprecision(2); // 2 places after '.'
		std::cout << std::left; //----------set alignment to left
		std::cout << std::setw(5) << counter
			<< std::setw(colWidth) << openAvg
			<< std::setw(colWidth) << highAvg
			<< std::setw(colWidth) << lowAvg
			<< std::setw(colWidth) << closeAvg << std::endl;

		//draw dashed line
		for (int i = 0; i < hr; i++)
		{
			std::cout << "_";
		}

		std::cout << std::endl;

		//second header row

		std::cout << std::setw(15) << ""
			<< std::setw(11) << "Price"
			<< std::setw(4) << "Date" << std::endl;

		//lowest row
		std::cout << std::setw(15) << "Lowest"
			<< "$" << std::setw(10) <<lowest
			<< std::setw(11) << lowestDate<<std::endl;

		//highest row
		std::cout << std::setw(15) << "Highest"
			<<"$"<< std::setw(10) << highest
			<< std::setw(11) << highestDate << std::endl;

		//draw dashed line
		for (int i = 0; i < hr; i++)
		{
			std::cout << "_";
		}
		std::cout << std::endl << std::endl << std::endl;

		std::cout << "Analyze another?(Y/n): " << std::endl;
		std::cin >> again;


		inputFile.close();



	}while (toupper(again)=='Y');



	std::cout << "Thank you for using Stock Price Analyzer" << std::endl;

	return 0;
}
