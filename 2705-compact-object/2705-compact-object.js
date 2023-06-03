/**
 * @param {Object} obj
 * @return {Object}
 */
function compactObject(obj) {
    // Handle array objets
    if (Array.isArray(obj)) return obj.filter(v => v).map(v => typeof v == 'object' ? compactObject(v) : v);

    // Handle map objects
    for (const key of Object.keys(obj)) {
        const val = obj[key];

        if (!val) {
            delete obj[key];
        } else if (typeof val == 'object') {
            obj[key] = compactObject(val);
        } 
    }

    return obj;
};