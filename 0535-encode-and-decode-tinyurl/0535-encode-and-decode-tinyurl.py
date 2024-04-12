class Codec:
    def __init__(self):
        self.d = {}
        self.index = 0

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        self.index += 1
        short = 'http://tinyurl.com/' + str(self.index)
        self.d[short] = longUrl
        return short

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.d[shortUrl]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))