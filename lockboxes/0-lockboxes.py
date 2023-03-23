#!/usr/bin/python3
"""Module checking if the boxes can all be unlocked"""


def canUnlockAll(boxes):
    """Returns True if all boxes can be opened or False if not"""
    open_boxes = {0: True}
    for i in range(1, len(boxes)):
        open_boxes.update({i: False})
    for i in range(len(boxes)):
        open_boxes = unlockBoxes(boxes, open_boxes, i)
    open_boxes = set(open_boxes.values())
    return True if len(open_boxes) == 1 else False


def unlockBoxes(boxes, open_boxes, index):
    """Unlock the boxes which had their keys in the box"""
    if open_boxes.get(index):
        for key in boxes[index]:
            is_opened = open_boxes.get(key)
            if key < index and not is_opened:
                open_boxes.update({key: True})
                open_boxes = unlockBoxes(boxes, open_boxes, key)
            if not is_opened:
                open_boxes.update({key: True})
    return open_boxes
