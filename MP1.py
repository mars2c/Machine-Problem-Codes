import random
import time

resources = []
users = []
user_usage = []
pointerOrder = []

#Generates the number of resources and users there will be 
#and stores them in a list
def GenerateValues(): 
    resourceNum = random.randint(1,5)
    for amount in range(1, resourceNum+1):
        resources.append(amount)
    print("--RESOURCES:", resources)
    usersamount = random.randint(1,5)
    for useram in range(1, usersamount+1):
        users.append(useram)
    print("--USERS:", users)        

#Assigns resources to a User and time it is used
def AssignResource_User(users, resources):
    assignlist = []
    userlen = len(users)
    for a in range(userlen):
        dictionary = {}
        resource_amount = len(resources)
        resource_indexes = random.sample(range(resource_amount), random.randint(1, resource_amount))
        for i in resource_indexes:
            resource_num = resources[i]
            if resource_num not in dictionary:
                dictionary[resource_num] = random.randint(1,5)
        assignlist.append(dictionary)
    assignlist = sorted(assignlist, key=lambda k: list(k.keys()))
    return assignlist

#Assigns the work queue
def ResourceQueue(users, assigned):
    queue = []
    for user in users:
        queueArr = []
        for resource in resources:
            if resource in assigned[user-1]:
                queueArr.append(assigned[user-1][resource])
            else:
                queueArr.append(0)
        queue.append(queueArr)
    #print("--TIME to be Used per RESOURCE:", queue)
    return queue  

def OrderPointer(arr): #Returns an array where the resource[a] = user
    pointerOrder = [-1 for a in range(len(resources))]
    for a in range(len(users)):
        counter = 0
        while True:
            if arr[a][counter] != 0 and pointerOrder[counter] == -1:
                pointerOrder[counter] = a
                break
            counter += 1
            if counter == len(resources):
                break
    return pointerOrder

def NextUser(arr, userList): #Returns the pointer which determines who the next user is
    for a in range(len(users)):
        counter = 0
        while True:
            if arr[a][counter] != 0 and userList[counter] == -1 and a not in userList:
                userList[counter] = a
            counter += 1
            if counter == len(resources):
                break
    return pointerOrder

def IfUserWaiting(resourceList, resourcenum, notinclude): #Determines if the user[a] is waiting in line to use the resource or not
    wait = ""
    for a in range(len(users)):
        if resourceList[a][resourcenum] != 0 and notinclude != users[a]:
            wait = wait + str(users[a]) + ", "
    return wait

def DisplayStatus(current, resourcequeue): #Displays the current status of the resources and the user currently using it, the time left, and the users "in waiting"
    print("Resource Status:")
    for i, resource in enumerate(resources):
        if current[i] != -1:
            print(f"R{resource} is currently being used by U{current[i]+1} for {resourcequeue[current[i]][i]} seconds.")
            print(f"*Users in waiting for Resource {resource}: {IfUserWaiting(resourcequeue, i, users[current[i]])}")
        else:
            print(f"R{resource} is free.")
    print("==============")

def Compile(resourceList, resourcequeue): #Calls the DisplayStatus() function to display the status of the resources at each iteration of the loop
    current = [-1] * len(resources)
    while True:
        print()
        time.sleep(1)
        print()
        DisplayStatus(current, resourcequeue)
        for i in range(len(resources)):
            if current[i] == -1:
                for j, queue in enumerate(resourcequeue):
                    if queue[i] != 0 and j not in current:
                        current[i] = j
                        break
            else:
                resourcequeue[current[i]][i] -= 1
                if resourcequeue[current[i]][i] == 0:
                    current[i] = -1
        if all(x == -1 for x in current):
            break

GenerateValues()
assigned = AssignResource_User(users, resources)
setup = ResourceQueue(users, assigned)
order = OrderPointer(setup)

Compile(order, setup)

        