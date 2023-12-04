class BagDemo {
    final static String APOLLO_LYRICS =
            "I bring truth and understanding " +
            "I bring wit and wisdom fair " +
            "Precious gifts beyond compare " +
            "We can build a world of wonder " +
            "I can make you all aware";

    final static String DIONYSUS_LYRICS =
            "I bring laughter, I bring Music " +
            "I bring joy and I bring Tears " +
            "I will soothe your primal fears " +
            "Throw off those chains of Reason " +
            "And your prison disappears";

    public static void main(String[] args) {
        // Split long string into an array of words (separated by spaces)
        String[] lyricsWordSequence = APOLLO_LYRICS.split(" ");

        // Won't need more capacity than there are words in the array
        Bag<String> wordsBag;
//        wordsBag = new BoundedArrayBag<>(lyricsWordSequence.length);
//        wordsBag = new DynamicArrayBag<>();
        wordsBag = new LinkedBag<>();

        // Add all words from the lyrics to the bag
        for (int i = 0; i < lyricsWordSequence.length; ++i) {
            String word = lyricsWordSequence[i];
            wordsBag.add(word);
        }

        // Ask bag for frequency of target word
        String keyWord = "I";
        System.out.println("The word '" + keyWord + "' occurs " + wordsBag.frequencyOf(keyWord) +
                " time(s) in the lyrics.");
    }
}
