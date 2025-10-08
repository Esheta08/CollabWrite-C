#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LineNode {
    char *line;
    struct LineNode *prev;
    struct LineNode *next;
} LineNode;

typedef struct {
    LineNode *head;
    LineNode *tail;
    int line_count;

    OperationStack *undoStack;
    OperationStack *redoStack;
} TextBuffer;

TextBuffer* createBuffer();

void insertLine(TextBuffer *buffer, int position, const char *text);
void deleteLine(TextBuffer *buffer, int position);
void updateLine(TextBuffer *buffer, int position, const char *newText);
void printBuffer(TextBuffer *buffer);
void freeBuffer(TextBuffer *buffer);

void undo(TextBuffer *buffer);
void redo(TextBuffer *buffer);

#endif