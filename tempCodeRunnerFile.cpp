while ((c = fgetc(file)) != EOF)
    {
        if (c == ' ')
        {
            CURRENT_OP_CODE = SPACE;
        }
        else if (c == ';')
        {
            CURRENT_OP_CODE = NEW_ROW;
        }
        else if (c == ']')
        {
            CURRENT_OP_CODE = MATRIX_END;
        }
        else if (isdigit(c) == 1 || c == '.')
        {
            CURRENT_OP_CODE = VALUE;
        }

        if (CURRENT_OP_CODE == VALUE && PREV_OP_CODE == VALUE)
        {
            currentValStr[currentValStrIndex] = c;
            currentValStrIndex++;
        }
        else if (CURRENT_OP_CODE == VALUE && CURRENT_OP_CODE != PREV_OP_CODE)
        {
            currentValStrIndex = 0;
            emptyCurrentValStr();
            currentValStr[currentValStrIndex] = c;
            currentValStrIndex++;
        }
        if (CURRENT_OP_CODE != VALUE && PREV_OP_CODE == VALUE)
        {
            currentValStrIndex = 0;
            currentMatrix.matrix[currentMatrix.current_row_index][currentMatrix.current_column_index] = atof(currentValStr);
            currentMatrix.current_column_index++;
        }

        if (CURRENT_OP_CODE == NEW_ROW)
        {
            currentMatrix.current_column_index = 0;
            currentMatrix.current_row_index++;
        }
        if (CURRENT_OP_CODE == MATRIX_END)
        {
            matricesArr[matricesArrCurrentIndex] = currentMatrix;
            matricesArrCurrentIndex++;
            currentMatrix = (Matlab_Matrix){
                {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, 0, 0};
            currentMatrix.current_row_index = 0;
        }
        // at end set PREV_OP_CODE
        PREV_OP_CODE = CURRENT_OP_CODE;
        CURRENT_OP_CODE = NO_OP;
    }