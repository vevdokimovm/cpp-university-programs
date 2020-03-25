from collections import deque

def person_is_seller(name):
    return name[-1::-1] == 'naysav'

def BFS(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if person_is_seller(person):
                print(person + " is a mango seller")
                return True
            else:
                searched.append(person)
                search_queue += graph[person]
    return False

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["vasyan", "lox", "retard"]
graph["alice"] = []
graph["claire"] = []
graph["vasyan"] = ["random guy", "Shrek"]
print(BFS("you"))