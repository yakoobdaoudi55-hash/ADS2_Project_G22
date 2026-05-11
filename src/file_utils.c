#include "../include/file_utils.h"
#include <stdio.h>
#include <stdlib.h>

/* Create empty binary file */
int createBinaryFile(const char* filename) {
    FILE* fp = fopen(filename, "wb"); // open for writing
    if (!fp) return -1;
    fclose(fp);
    return 0;
}

/* Write one record to file (append mode) */
int writeRecord(const char* filename, Record* r) {
    FILE* fp = fopen(filename, "ab"); // append mode
    if (!fp) return -1;
    fwrite(r, sizeof(Record), 1, fp); // write struct bytes
    fclose(fp);
    return 0;
}

/* Read record at given index */
int readRecord(const char* filename, int index, Record* r) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return -1;
    fseek(fp, index * sizeof(Record), SEEK_SET); // jump to record position
    int result = fread(r, sizeof(Record), 1, fp);
    fclose(fp);
    return (result == 1) ? 0 : -1;
}

/* Count total records in file */
int countRecords(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return -1;
    fseek(fp, 0, SEEK_END);       // go to end of file
    long size = ftell(fp);        // get file size in bytes
    fclose(fp);
    return (int)(size / sizeof(Record)); // number of records
}

/* Append record to end of file */
int appendRecord(const char* filename, Record* r) {
    return writeRecord(filename, r); // reuse write in append mode
}

/* Search record by ID — returns index or -1 */
int searchRecordById(const char* filename, int id, Record* result) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return -1;
    Record r;
    int index = 0;
    while (fread(&r, sizeof(Record), 1, fp) == 1) {
        if (r.id == id) {       // compare IDs
            *result = r;
            fclose(fp);
            return index; // return position
        }
        index++;
    }
    fclose(fp);
    return -1; // not found
}

/* Update record at index with new data */
int updateRecord(const char* filename, int index, Record* newData) {
    FILE* fp = fopen(filename, "r+b"); // read+write mode
    if (!fp) return -1;
    fseek(fp, index * sizeof(Record), SEEK_SET); // go to record position
    fwrite(newData, sizeof(Record), 1, fp);       // overwrite record
    fclose(fp);
    return 0;
}

/* Copy all records from src to dest */
int copyBinaryFile(const char* src, const char* dest) {
    FILE* in  = fopen(src,  "rb"); // source file
    FILE* out = fopen(dest, "wb"); // destination file
    if (!in || !out) { if(in) fclose(in); if(out) fclose(out); return -1; }
    Record r;
    while (fread(&r, sizeof(Record), 1, in) == 1)
        fwrite(&r, sizeof(Record), 1, out); // copy record by record
    fclose(in);
    fclose(out);
    return 0;
