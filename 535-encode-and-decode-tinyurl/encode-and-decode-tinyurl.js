const encodeMap = new Map();
const decodeMap = new Map();
let counter = 1;
const baseUrl = 'http://tinyurl.com/';

var encode = function (longUrl) {
    if (encodeMap.has(longUrl)) {
        return baseUrl + encodeMap.get(longUrl);
    }

    const key = counter++;
    encodeMap.set(longUrl, key);
    decodeMap.set(key, longUrl); // Store key to longUrl mapping in decodeMap
    return baseUrl + key;
};


var decode = function (shortUrl) {
    const key = +shortUrl.replace(baseUrl, ''); // Parse key from shortUrl
    return decodeMap.get(key);
};

/**
 * Your functions will be called as such:
 * decode(encode(url));
 */