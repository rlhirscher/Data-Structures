{-

Ryan Hirscher
CSC4510 Programming Language Design
10/17/2023
Haskel Task Manager (To-do list)

This is a Haskell program a Task Manager with IO. This was designed in to explore the functional paradigm and gain an opinion of its merits. The program will prompt the user for an input 1-4. Input is handled by IO and with a switch statement. Any other input (not 1-4) is disregarded and gets reprompted. 1 will allow the user to add a task and a description. 2 will remove a task. 3 will display the tasks. 4 will quit the program. 

Note: Input validation is not strong. A string may be entered for a Task ID to be removed and it will say its removed (even though nothing happened).

Compile:
ghc Tasks.hs

Execute:
./Tasks

-}


import System.IO
import Control.Exception
import Data.List

-- Define a task data structure
-- Task ID as an integer, String for Name, and String for description
data Task = Task { taskId :: Int, taskName :: String, taskDescription :: String } deriving (Show)

-- Create a list to store tasks
type TaskList = [Task]

-- Function to add a task to the task list. Both Strings.
addTask :: TaskList -> String -> String -> TaskList
addTask taskList name desc =
    let taskId' = if null taskList then 1 else taskId (last taskList) + 1
        newTask = Task taskId' name desc
    in taskList ++ [newTask]

-- Function to remove a task by ID (1-4)
removeTask :: TaskList -> Int -> TaskList
removeTask taskList idToRemove = filter (\task -> taskId task /= idToRemove) taskList

-- Function to display tasks, Simple output with Name - Description
displayTasks :: TaskList -> IO ()
displayTasks taskList = do
    putStrLn "Tasks:"
    mapM_ (\task -> putStrLn $ show (taskId task) ++ ". " ++ taskName task ++ " - " ++ taskDescription task) taskList

-- Function to handle user input and perform actions.
-- Recursive function, 4 does not re-call
handleInput :: TaskList -> IO ()
handleInput taskList = do
    putStrLn "\nOptions:"
    putStrLn "1. Add a task"
    putStrLn "2. Remove a task"
    putStrLn "3. Display tasks"
    putStrLn "4. Quit"
    putStr "Enter your choice: "
    hFlush stdout
    choice <- getLine
    case choice of
        "1" -> do
            putStr "Enter task name: "
            hFlush stdout
            name <- getLine
            putStr "Enter task description: "
            hFlush stdout
            desc <- getLine
            let newTaskList = addTask taskList name desc
            putStrLn "Task added!"
            handleInput newTaskList
        "2" -> do
            putStr "Enter task ID to remove: "
            hFlush stdout
            input <- getLine
            let idToRemove = read input :: Int
                newTaskList = removeTask taskList idToRemove
            putStrLn "Task removed!"
            handleInput newTaskList
        "3" -> do
            displayTasks taskList
            handleInput taskList
        "4" -> putStrLn "Goodbye!"
        _ -> do
            putStrLn "Invalid choice. Please try again."
            handleInput taskList

main :: IO ()
main = do
    putStrLn "Welcome to Ryan's Task Manager!"
    handleInput []

