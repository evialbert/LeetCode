public class Codec {
    Map<String, String> mp = new HashMap<>();
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        String hashCode=longUrl.hashCode()+""; 
        mp.put(hashCode,longUrl);
        return hashCode;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return mp.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));