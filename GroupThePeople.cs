//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
public class Solution {
    
    public IList<IList<int>> GroupThePeople(int[] groupSizes) {
        IList<IList<int>> completedGroups = new List<IList<int>>();
        
        
        Dictionary<int, List<int>> incompleteGroups= new Dictionary<int, List<int>>();
        
        //iterate over all the members and add them to incomplete groups
        for(int x = 0; x < groupSizes.Length; x++)
        {
            if( !incompleteGroups.ContainsKey(groupSizes[x]) )
            {
                incompleteGroups[groupSizes[x]] = new List<int>();
            }
            incompleteGroups[groupSizes[x]].Add(x);
            
            if(incompleteGroups[groupSizes[x]].Count >= groupSizes[x])
            {
                completedGroups.Add(incompleteGroups[groupSizes[x]]);
                incompleteGroups[groupSizes[x]] = new List<int>();
            }
        }
        
        return completedGroups;
    }
}