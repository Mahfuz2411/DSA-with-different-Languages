class graph_without_weight_value:
  def __init__(self):
    self.graph = {}
  
  def graph_with_fixed_input(self):
    self.graph = {
      "A": ["B", "C"],
      "B": ["A", "D", "E"],
      "C": ["A", "F"],
      "D": ["B"],
      "E": ["B", "F"],
      "F": ["C", "E"]
    }
    self.print_graph()

  def graph_with_user_input():
    pass

  def print_graph(self):
    for node in self.graph:
      print(node, end=" -> ")
      for adjNode in self.graph[node]:
        print(adjNode, end=" ")
      print()

def main():
  obj = graph_without_weight_value()
  obj.graph_with_fixed_input()
  
  
if __name__=="__main__":
  main() 