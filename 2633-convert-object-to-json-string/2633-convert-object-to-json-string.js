/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if (typeof object === "string") return `"${object}"`;
    if (typeof object === "number" || typeof object === "boolean") return object;
    if (Array.isArray(object)) return `[${object.map(o => jsonStringify(o)).join(",")}]`;
    if (typeof object === "object") {
        if (object === null) return "null";
        else return `{${(Object.keys(object).map(o => `"${o}":${jsonStringify(object[o])}`)).join(",")}}`;
    }

    return "";
};