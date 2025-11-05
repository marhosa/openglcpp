clc;
clear;

% stores the data of all users as a 2d matrix
global Database;
Database = {};

% HELPER FUNCTIONS:
% just make spaces to make the terminal clean
function [] = Spacer(x)
    for i = 1:x
        fprintf('\n');
    end
end;

% show the menu
function [] = ShowMenu()
    fprintf('\n--- UTANG TRACKER PRO MAX ---\n');
    fprintf('[1] LOG BORROWER\n');
    fprintf('[2] SEARCH BORROWER (ID OR NAME)\n');
    fprintf('[3] TOTAL POSSIBLE PROFIT\n');
    fprintf('[4] AVERAGE LOAN\n');
    fprintf('[5] SHOW ALL LOANERS\n')
    fprintf('[6] REMOVE BORROWER FROM LOG\n');
    fprintf('[7] GET ULTRA HIGH BORROWERS\n');
    fprintf('[8] EXIT\n');
end;

% gives available id
function [freeID] = MakeID()
    global Database;
    if isempty(Database) % id of 1 if first user
        freeID = 1; 
    else % otherwise traverse until a free id is found 
        existingIDs = sort([Database{:,1}]);
        freeID = 1;
        while ismember(freeID, existingIDs)
            freeID = freeID + 1;
        end;
    end;
end;



% CREATE FUNCTIONS:
% log an utang
function [] = LogUtang(id, name, utangPrice)
    global Database;
    profit = (utangPrice + (utangPrice * 0.20)) - utangPrice; % calculate 5/6 loaning profit
    newData = {id, name, utangPrice, profit};
    Database = [Database; newData]; % add data row to the database
end;


% READ FUNCTOINS:
% search by name or id then print it
function x = FindUser(searchQuery)
    global Database;
    if isempty(Database)
        fprintf('DATABASE IS EMPTY...\n');
        x = 0;
        return;
    end

    userFound = false;
    for i = 1:size(Database, 1)
        % strcmpi compares strings, first tries to compare it to a number,
        % second compares it to a name
        if strcmpi(string(searchQuery), string(Database{i, 1})) || strcmpi(lower(string(searchQuery)), lower(string(Database{i, 2})))
            idRet = Database{i, 1};
            name = Database{i, 2};
            utangprice = Database{i, 3};
            profit = Database{i, 4};
            fprintf('ID: %i\nNAME: %s\nLOANED: %.2f\nPROFIT: %.2f', idRet, name, utangprice, profit);
            userFound = true;
            break;
        end;
    end;
    if ~(userFound)
        fprintf('\nUSER NOT FOUND...');
    end;
end;

% get total profit from all users
function totalProfit = getTotalProfit()
    global Database;
    if isempty(Database) % empty database makes profit to zero
        fprintf('DATABASE IS EMPTY...\n');
        totalProfit = 0;
        return;
    end;

    totalProfit = sum([Database{:, 4}]); % take all 4th element from every row and sum it
end;

% get total utangPrice
function averageLoan = getAverageLoan()
    global Database;
    if isempty(Database) % total loans given is zero if empty database
        fprintf('DATABASE IS EMPTY...\n');
        averageLoan = 0;
        return;
    end;

    averageLoan = mean([Database{:, 3}]); % take all 3rd element from every row and sum it
end;

% display ALL people who loaned from you
function x = displayTotalUtangers()
    global Database;
    if isempty(Database)
        fprintf('\nDATABASE IS EMPTY...\n');
        x = 0;
        return;
    
    else
        % traverses the database and prints the id and name
        for i = 1:size(Database, 1)
            fprintf('\n    %i - %s', Database{i, 1}, Database{i, 2});
        end;

    end;
end;


% get all ultra high borrowers with > 100000 utang and the top borrower
function highBorrowers = getTopBorrowers()
    global Database;
    if isempty(Database)
        fprintf('DATABASE IS EMPTY...\n');
        highBorrowers = [];
        return;
    end
    
    % Extract all loan amounts into a new vector
    loanAmounts = [Database{:,3}];
    
    % extract third column
    highIdx = loanAmounts > (100000 - 1); % a vector that determines borrowers with six digit loans
    highBorrowers = Database(highIdx, :); % filter it with logical indexing
    
    % get borrowers with loans with six digits
    fprintf('\n-- BORROWERS WITH SIX DIGIT LOANS --\n');
    if isempty(highBorrowers)
        fprintf('None...\n');
    else
        for i = 1:size(highBorrowers,1)
            fprintf('ID: %i | NAME: %s | LOANED: %.2f\n', ...
                highBorrowers{i,1}, highBorrowers{i,2}, highBorrowers{i,3});
        end
    end
    
    % use max function to get index of largest borrower
    [val, indexMax] = max(loanAmounts); % get the value and index
    largestBorrower = Database(indexMax, :); % get row with the largest borrower
    
    fprintf('\n-- LARGEST BORROWER --\n');
    fprintf('NAME: %s | LOANED: %.2f\n', largestBorrower{2}, val);
end




% DELETE FUNCTIONS:
% delete a user by id
function [] = DeleteUser(id)
    global Database;
    Spacer(60);
    for i = 1:size(Database, 1)
        if (id == Database{i, 1})
            Database(i, :) = []; % remove the person from the list, assign row into none
            fprintf('BORROWER WITH ID %i DELETED SUCCESSFULLY!\n', id);
            return; % Exit the function after deletion
        end;
    end
    fprintf('BORROWER NOT FOUND...');
end;


Spacer(60);

% MAIN CODE HERE
while (true)
    ShowMenu();
    choice = input('Choice: ');
    
    % switch case of the menu
    switch choice
        % input user loan
        case 1
            fprintf('\n-- FILL OUT THE FORM --\nNAME: ');
            name = input('', 's');
            utangPrice = input('LOAN AMOUNT: ');
            givenId = MakeID();
            LogUtang(givenId, name, utangPrice);
            Spacer(30);
            fprintf('LOAN LOGGED SUCCESSFULLY!\nID NUMBER IS: %i\n', givenId);
    
        % search for user by name or id and show their status
        case 2
            fprintf('\n-- SEARCH FOR ID OR NAME --\nQuery: ');
            searchQuery = input('', 's');
            Spacer(60);
            FindUser(searchQuery);
            fprintf('\n');
    
        % show total possible profit that can be gained
        case 3
            totalProfit = getTotalProfit();
            Spacer(60);
            fprintf('TOTAL POSSIBLE PROFIT: %.2f\n', totalProfit);
            
        % show total amount of loans currently given to lenders
        case 4
            avgLoan = getAverageLoan();
            Spacer(60);
            fprintf('THE AVERAGE LOAN IS: %.2f\n', avgLoan);
    
        % show all ID and NAMES of all lenders
        case 5
            % Display all loaners
            Spacer(60);
            fprintf('ALL PEOPLE AND THEIR RESPECTIVE IDs');
            displayTotalUtangers();
            
    
        % delete utang log by ID and only ID
        case 6
            fprintf('Enter ID to delete (NUMBER): ');
            idToDelete = input('');
            DeleteUser(idToDelete);

        case 7
            Spacer(60);
            getTopBorrowers();
        
        % end the program
        case 8
        clc;
        return
    end;
end;
