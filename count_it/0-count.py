#!/usr/bin/python3
"""
0-count module
"""
import operator
import requests


def count_words(subreddit, word_list, after='', count={}):
    """
    Counts the number of occurences of the word in word_list on a specific
    subreddit.
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after != '':
        url += '?after={}'.format(after)
    user = {'User-Agent': 'CountIt'}
    response = requests.get(url, headers=user, allow_redirects=False)
    if response.ok is False or response.status_code == 302:
        return
    data = response.json().get('data')
    after = data.get('after')
    for post in data.get('children'):
        for word in post.get('data').get('title').casefold().split():
            if word in [keyword.casefold() for keyword in word_list]:
                if word not in count.keys():
                    count[word] = 1
                else:
                    count[word] += 1
    sorted_dict = dict(sorted(count.items(),
                              key=operator.itemgetter(1),
                              reverse=True))
    if after is None:
        for key, value in sorted_dict.items():
            if value > 0:
                print('{}: {}'.format(key, value))
        return
    count_words(subreddit, word_list, after, count)
