#!/usr/bin/python3
"""0-count module"""
import requests


def count_words(subreddit, word_list, after='', count={}):
    """Counts the number of occurences of word_list's words."""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after != '':
        url += '?after={}'.format(after)
    user = {'User-Agent': 'CountIt'}
    response = requests.get(url, headers=user, allow_redirects=False)
    if response.status_code > 300:
        return
    data = response.json().get('data')
    after = data.get('after')
    check_titles(count, word_list, data.get('children'))
    if after is None:
        print_result(count)
        return
    count_words(subreddit, word_list, after, count)


def print_result(count):
    """Prints the result of the search."""
    sorted_dict = dict(sorted(count.items(), key=lambda x: x[1], reverse=True))
    for key, value in sorted_dict.items():
        if value > 0:
            print('{}: {}'.format(key, value))


def check_titles(count, word_list, posts):
    """Check if the titles contain words from word_list."""
    for post in posts:
        for word in post.get('data').get('title').lower().split():
            if word in [keyword.lower() for keyword in word_list]:
                if word not in count.keys():
                    count[word] = 1
                else:
                    count[word] += 1
