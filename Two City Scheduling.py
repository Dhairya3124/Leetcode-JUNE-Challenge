def twoCitySchedCost (costs: List[List[int]]) -> int:
        
  costs.sort(key = lambda x: x[0]-x[1])
        
  return sum(i[0] for i in costs[:len(costs)//2]) +sum(j[1] for j in costs[len(costs)//2:])
