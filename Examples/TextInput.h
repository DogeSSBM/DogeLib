#ifndef TEXTINPUT_H
#define TEXTINPUT_H

// typedef struct Itlist{
//     InText it;
//     struct Itlist *next;
// }Itlist;
//
// Itlist* itlistNew(const InText it)
// {
//     Itlist *list = calloc(1, sizeof(Itlist));
//     list->it = it;
//     return list;
// }
//
// Itlist* itlistAppend(Itlist *head, Itlist *tail)
// {
//     if(!head)
//         return tail;
//     Itlist *cur = head;
//     while(cur->next)
//         cur = cur->next;
//     cur->next = tail;
//     return head;
// }
//
// Itlist* itlistFree(Itlist *list)
// {
//     if(!list)
//         return NULL;
//     Itlist *next = list->next;
//     inTextFree(list->it);
//     free(list);
//     return next;
// }
//
// void itlistFreeAll(Itlist *list)
// {
//     while(list)
//         list = itlistFree(list);
// }
//
// Itlist* itlistDelete(Itlist *list, Itlist *del)
// {
//     if(!list)
//         return NULL;
//     if(!del)
//         return list;
//     if(list == del)
//         return itlistFree(list);
//     Itlist *cur = list->next;
//     while(cur->next && cur->next != del)
//         cur = cur->next;
//     if(!cur->next)
//         return list;
//     Itlist *next = cur->next->next;
//     inTextFree(cur->next->it);
//     free(cur->next);
//     cur->next = next;
//     return list;
// }
//
// void itlistDrawAll(Itlist *list)
// {
//     while(list){
//         setTextSize(list->it.fontSize);
//         setTextColor(list->it.fontColor);
//         drawTextCoord(list->it.text, list->it.pos);
//         list = list->next;
//     }
// }
//
bool inputDone(void)
{
    if(!inTextIsEnabled() || !keyPressed(SC_RETURN))
        return false;
    inTextReset();
    return true;
}

int example(void)
{
    init();
    InText it = inTextNew(getWindowMid(), 12, WHITE);
    inTextStart(&it, inputDone);
    while(1){
        const uint t = frameStart();

        if(keyPressed(SC_ESCAPE)){
            if(inTextIsEnabled())
                inTextFree(it);
            exit(EXIT_SUCCESS);
        }

        if(!inTextIsEnabled() && keyReleased(SC_RETURN))
            inTextStart(&it, inputDone);

        inTextDraw(it);

        frameEnd(t);
    }
}

#endif /* end of include guard: TEXTINPUT_H */
