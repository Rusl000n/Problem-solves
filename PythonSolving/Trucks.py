def the_task_of_loading_boxes_into_a_truck(boxes):
    global capasity, cnt
    if boxes <= capasity:
        cnt += 1
        return capasity
    else:
        if boxes%2==0:
            return the_task_of_loading_boxes_into_a_truck(boxes//2)+the_task_of_loading_boxes_into_a_truck(boxes//2)
        else:
            return the_task_of_loading_boxes_into_a_truck(boxes//2)+the_task_of_loading_boxes_into_a_truck((boxes//2)+1)


boxes, capasity = map(int, input().split())
cnt = 0
the_task_of_loading_boxes_into_a_truck(boxes)
print(cnt)