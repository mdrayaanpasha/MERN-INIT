#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main(int argc, char *argv[]) {
    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  YELLO:) \n \t\t\t\t\tHow you doin'? so new project, huh?\n\n");
    printf("\n============================================================================================\n");
    Sleep(5);

    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Making frondend & backend folders....n\n");
    printf("\n============================================================================================\n");

    system("mkdir frontend && mkdir backend");

    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Initializing React.....n\n");
    printf("\n============================================================================================\n");

    system("cd frontend && npm create vite@latest . && npm install && npm i axios react-router-dom");


    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Intializing Express & NodeJs....n\n");
    printf("\n============================================================================================\n");

    system("cd backend && npm init -y && npm i express mongoose cors body-parser multer");

    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Removing unncessary CSS & Creating Components & imgs folder in React....n\n");
    printf("\n============================================================================================\n");

    system("del frontend\\src\\App.css");

    // Write boilerplate code to App.jsx
    FILE *file = fopen("frontend\\src\\App.jsx", "w");
    if (file == NULL) {
        perror("Error opening App.jsx");
        return 1;
    }

    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Writing Boiler Plate for React Homepage & Routing.....n\n");
    printf("\n============================================================================================\n");

    const char *boilerplate_code =
        "import React from 'react';\n"
        "import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';\n"
        "import Home from './components/Home';\n"
        "import './index.css';\n"
        "\n"
        "const App = () => {\n"
        "    return (\n"
        "        <Router>\n"
        "            <Routes>\n"
        "                <Route path='/' element={<Home />} />\n"
        "            </Routes>\n"
        "        </Router>\n"
        "    );\n"
        "};\n"
        "\n"
        "export default App;\n";

    fputs(boilerplate_code, file);
    fclose(file);

    system("cd frontend\\src\\ && mkdir components");




    system("cd frontend\\src\\assets && mkdir css && mkdir imgs");

    //another Last thing left is to remove css import from main that could be done by:

    file = fopen("frontend\\src\\main.jsx", "w");
    if (file == NULL) {
        perror("Error opening main.js");
        return 1;
    }

    const char *main_code =
        "import { StrictMode } from 'react';\n"
        "import { createRoot } from 'react-dom/client';\n"
        "import App from './App.jsx';\n"
        "import './index.css';\n"

        "\n"
        "createRoot(document.getElementById('root')).render(\n"
        "  <StrictMode>\n"
        "    <App />\n"
        "  </StrictMode>\n"
        ");\n";

    fputs(main_code, file);
    fclose(file);


    //last for now: tailwind in react.

    system("cd frontend && npm install -D tailwindcss && npx tailwindcss init && npm i tailwindcss ");

    //now lets change the the tailwind configuration
    FILE *fileP = fopen("frontend\\tailwind.config.js", "w");
    if (fileP == NULL) {
        perror("Error opening frontend/tailwind.config.js");
        return 1;
    }

    const char *tailwind_config_content =
        "/** @type {import('tailwindcss').Config} */\n"
        "export default {\n"
        "content: [\n"
        "    './src/**/*.{js,jsx,ts,tsx}',\n"
        "],\n"
        "theme: {\n"
        "    extend: {},\n"
        "},\n"
        "plugins: [],\n"
        "}\n";

    fputs(tailwind_config_content,fileP);
    fclose(fileP);


    //lets also make those postcss configration once for all.

    system("cd frontend && npm install -D postcss autoprefixer");
    FILE *postcss_file = fopen("frontend\\postcss.config.js", "w");
    if (postcss_file == NULL) {
        perror("Error opening postcss.config.js");
        return 1;
    }

    const char *postcss_config_content =
        "export default {\n"
        "  plugins: {\n"
        "    tailwindcss: {},\n"
        "    autoprefixer: {},\n"
        "  },\n"
        "};\n";

    fputs(postcss_config_content, postcss_file);
    fclose(postcss_file);



    //now lets add tailwind thing in index.css



    fileP = fopen("frontend\\src\\index.css", "w");
    if (fileP == NULL) {
        perror("Error opening frontend/src/index.css");
        return 1;
    }

    const char *index_css_content =
    "@tailwind base;\n"
    "@tailwind components;\n"
    "@tailwind utilities;\n";

    fputs(index_css_content,fileP);
    fclose(fileP);


    //lets make boilerplate of it in homepage:

    file = fopen("frontend\\src\\components\\Home.jsx", "w");
    if (file == NULL) {
        perror("Error opening Home.jsx");
        return 1;
    }

    const char *home_code =
        "import React from 'react';\n"
        "\n"
        "const Home = () => {\n"
        "    return (\n"
        "    <h1 className='text-3xl font-bold underline'> Hello world! </h1> \n"
        "    );\n"
        "};\n"
        "\n"
        "export default Home;\n";

    fputs(home_code, file);
    fclose(file);









    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Done With Frontend stuff, workin on backend.......n\n");
    printf("\n============================================================================================\n");




    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  creating DataBase & changing package.json....n\n");
    printf("\n============================================================================================\n");
    system("mkdir backend\\DB");


    fileP = fopen("backend\\package.json", "w");
    if (fileP == NULL) {
        perror("Error opening backend/package.json");
        return 1;
    }

    const char *package_json_content =
        "{\n"
        "  \"name\": \"backend\",\n"
        "  \"version\": \"1.0.0\",\n"
        "  \"main\": \"index.js\",\n"
        "  \"type\": \"module\",\n"
        "  \"scripts\": {\n"
        "    \"test\": \"echo \\\"Error: no test specified\\\" && exit 1\"\n"
        "  },\n"
        "  \"keywords\": [],\n"
        "  \"author\": \"\",\n"
        "  \"license\": \"ISC\",\n"
        "  \"description\": \"\",\n"
        "  \"dependencies\": {\n"
        "    \"express\": \"^4.21.1\"\n"
        "  }\n"
        "}";

    fputs(package_json_content, fileP);
    fclose(fileP);

  printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Boiler Plate for index.js with DB Connection....n\n");
    printf("\n============================================================================================\n");

   // Write boilerplate code to index.js
file = fopen("backend\\index.js", "w");
if (file == NULL) {
    perror("Error opening index.js");
    return 1;
}

const char *backend_code_template =
    "import express from 'express';\n"
    "import mongoose from 'mongoose';\n"
    "import cors from 'cors';\n"
    "import bodyParser from 'body-parser';\n"
    "\n"
    "const app = express();\n"
    "const port = 5000;\n"
    "const mongoURI = 'mongodb://localhost:27017/%s';\n"  // Use %s for database name
    "\n"
    "app.use(cors());\n"
    "app.use(bodyParser.json());\n"
    "app.use(bodyParser.urlencoded({ extended: true }));\n"
    "\n"
    "// MongoDB Connection\n"
    "mongoose.connect(mongoURI, { useNewUrlParser: true, useUnifiedTopology: true })\n"
    "    .then(() => console.log('MongoDB connected...'))\n"
    "    .catch(err => console.log('MongoDB connection error:', err));\n"
    "\n"
    "// Define a simple route\n"
    "app.get('/', (req, res) => {\n"
    "    res.send('Welcome to the Backend API');\n"
    "});\n"
    "\n"
    "app.listen(port, () => {\n"
    "    console.log(`Server running at http://localhost:${port}`);\n"
    "});\n";

char backend_code[2000];
snprintf(backend_code, sizeof(backend_code), backend_code_template, argv[1]);

if (fputs(backend_code, file) == EOF) {
    perror("Error writing to index.js");
    fclose(file);
    return 1;
}

fclose(file);



    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t  Backend Complete, Working on Making Github Repo....n\n");
    printf("\n============================================================================================\n");

    int status = system("git init");
    if (status != 0) {
        perror("Failed to initialize Git repository");
        return 1;
    }

    status = system("git add .");
    if (status != 0) {
        perror("Failed to add files to staging area");
        return 1;
    }

    status = system("git commit -m \"Initial commit\"");
    if (status != 0) {
        perror("Failed to commit files");
        return 1;
    }

    char create_repo_command[256];
    snprintf(create_repo_command, sizeof(create_repo_command),
             "gh repo create %s --public --source=. --remote=origin --push", argv[1]);
    status = system(create_repo_command);
    if (status != 0) {
        perror("Failed to create GitHub repository");
        return 1;
    }

    status = system("git branch | grep 'main' > /dev/null");
    if (status == 0) {
        status = system("git push -u origin main");
    } else {
        status = system("git push -u origin master");
    }

    if (status != 0) {
        perror("Failed to push to GitHub");
        return 1;
    }

    printf("\n============================================================================================\n");
    printf("\n\t\t\t\t\t Everything Completed.....n\n");
    printf("\n\t\t\t\t\t Now Cd frontend && npm run dev...\n");
    printf("\n\t\t\t\t\t Also Cd backend && npx nodemon...\n");
    printf("\n============================================================================================\n");


    return 0;
}
