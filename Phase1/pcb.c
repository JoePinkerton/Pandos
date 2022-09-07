#include "../h/types.h"
#include "../h/const.h"

pcb_PTR pcbFree_h;

/*add pcb on free list */
void freePcb(pcb_PTR p)
{
    p -> p_next = pcbFree_h;
    pcbFree_h = p;
}
/*initialize the PCB */
pcb_PTR allocPcb()
{
    if(pcbFree_h == NULL)
    {
        return NULL;
    }
    pcb_PTR temp;
    temp = pcbFree_h;
    pcbFree_h = pcbFree_h -> p_next;
    temp -> p_next = NULL;
    temp -> p_prev = NULL;
    /* tree */
    temp -> p_prnt = NULL;
    temp -> p_child = NULL;
    temp -> p_sib_next = NULL;
    temp -> p_sib_prev = NULL;
    temp -> p_semAdd = NULL;
    temp -> p_supportStruct = NULL;
    return temp;
int emptyProcQ(pcb_t *tp) {
    return(tp == NULL);
}

pcb_t *headProc(pcb_t *tp) {
    if(emptyProcQ(tp)) {
        return NULL;
    }
    return (tp -> p_next);
}

pcb_t *mkEmptyProcQ() {
    return NULL;
}

void insertProcQ(pcb_t **tp, pcb_t *p) {
    if (emptyProc(tp) {
        *(tp) = p;
        p -> p_next = p;
        p -> p_prev = p;
        return;
    }
    *(tp) = R;
    R -> p_next = Q;
    R -> p_prev = N;
    R -> p_next = N;
    N -> p_prev = Q;
    N -> p_next = Q;
    R -> p_next = NULL;
    R -> p_prev = NULL;

}

initPcbs() {
    static pcb_t initArray[MAXPCBCNT];
    for (int i = 0; i < MAXPCBCNT; i++) {
        allocPcbs(&initArray[i]);
    }
}

pcb_t *removeProcQ(pcb_t **tp) {
    if (emptyProcQ(tp)) {
        return NULL;
    } else {
        *(tp) = P;
        pcb_t temp = p -> p_prev;
        temp = temp -> p_next;
        p = NULL;
        p -> p_prev = Q;
        p -> p_next = R;
        Q -> p_next = R;
        R -> p_prev = Q;
        if (tp -> p_next == p) {
            tp -> p_next = Q;
        }
        return (temp);
    }
}
/* take a PCB out of the queue of some TP and then returns it */
pcb_PTR outProcQ(pcb_PTR *tp, pcb_PTR p){
    pcb_PTR final;
    /* empty case */
    if ((emptyProcQ(*tp) || (p == NULL)))
    {
        return NULL;
    }
    /* single case */
    if((*tp)==p)
    {
        return removeProcQ(*tp);
    }
    pcb_PTR temp;
    /* begin to chug through the list looking for our removeable PCB */
    temp = (*tp) -> p_next;
    while(temp != (*tp))
    {
        if(temp == p)
        {
            /* set all notable fields equal to the one being removed */
            final = temp;
            final -> p_prev -> p_next = temp -> p_next;
            final -> p_next -> p_prev = temp -> p_prev;
            final -> p_next = NULL;
            final -> p_prev = NULL;
            return final;
        }
        temp = temp -> p_next;
    }
    return NULL
}
/*         Trees                 */

int emptyChild(pcb_t *p) {
    return(p -> p_child = NULL);
}

void insertChild (pcb_t *prnt, pcb_t *p){
    p -> p_prnt = prnt;
    prnt -> p_child = p;
}
