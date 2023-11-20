#include "defs.h"

RoomType* createRoom(char* roomNameIn){
    //    char roomName[MAX_STR]; 
                //Already initilized
    //    GhostType *roomGhost;
    //    RoomListType connectedRooms;
    //    EvidenceListType roomEvList;
    //    HunterType* hunters[NUM_HUNTERS];

    RoomType *newRoom = (RoomType*) calloc(1, sizeof(RoomType));
    //room name
    strcpy(newRoom->roomName, roomNameIn);

    //roomList
    initRoomList(&newRoom->connectedRooms);

    //evidence list
    initEvidenceList(&newRoom->roomEvList);

    //hunter array
    initHuntersArray(newRoom->hunters);

    return newRoom;
}

void initRoomList(RoomListType *list){
    list->head = NULL;
    list->tail = NULL;
}

void connectRooms(RoomType* firstRoom, RoomType* secondRoom){
    addRoom(&firstRoom->connectedRooms, secondRoom);
    addRoom(&secondRoom->connectedRooms, firstRoom);
}

void printRoomList(RoomListType *list){
    RoomNodeType *currNode = list->head;
    while(currNode != NULL){
        printRoom(currNode->data);
        currNode = currNode->next;
    }
}

void printRoom(RoomType *room){
    printf("room name: %s\n", room->roomName);

}
void addRoom(RoomListType *list, RoomType *room){
    // NodeType *listTail = list->tail;
    // NodeType *listHead = list->head;
    
    RoomNodeType *newNode =  (RoomNodeType*) calloc(1, sizeof(RoomNodeType));
    newNode->data = room;
    newNode->next = NULL;

    // if size = 0, add to head, head.next = tail, tail = NULL
    if (list->tail == NULL && list->head == NULL){
        list->head = newNode;
    }
    //if size = 1, tail = newNode
    else if(list->head != NULL && list->tail == NULL){
        list->tail = newNode;
        list->head->next = list->tail;
    }
    else{
        list->tail->next = newNode;
        list->tail = list->tail->next;
    }
}