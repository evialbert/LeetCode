/**
 * @param {string[]} folder
 * @return {string[]}
 */
var removeSubfolders = function(folder) {
    if(folder.length === 0) return 0

    folder.sort()
    let result = [folder[0]]
    
    for(let i=1; i < folder.length; i++){
        let lastFolder = result[result.length - 1] + '/'
        if(!folder[i].startsWith(lastFolder)){
            result.push(folder[i])
        }
    }

    return result
};