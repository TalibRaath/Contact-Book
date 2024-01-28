<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 20px;
        }

        h1 {
            color: #0366d6;
        }

        h2 {
            color: #24292e;
        }

        p {
            margin-bottom: 20px;
        }

        code {
            background-color: #f6f8fa;
            padding: 2px 4px;
            border-radius: 4px;
            font-family: SFMono-Regular, Consolas, Liberation Mono, Menlo, Courier, monospace;
            color: #24292e;
        }

        ol {
            list-style-type: none;
            counter-reset: my-counter;
        }

        li {
            counter-increment: my-counter;
            margin-bottom: 10px;
        }

        li::before {
            content: counter(my-counter);
            color: #0366d6;
            font-weight: bold;
            margin-right: 10px;
        }
    </style>
    <title>Contact Book Console App</title>
</head>

<body>
    <h1>Contact Book Console App</h1>

    <h2>Project Description:</h2>
    <p>
        The Contact Book Console App is a straightforward and efficient application crafted using object-oriented
        programming (OOP) concepts in C++. This project functions as a digital contact management system, empowering
        users to execute various operations like adding, editing, and deleting contacts within a console interface. The
        implementation exemplifies fundamental OOP principles such as encapsulation, inheritance, and polymorphism,
        fostering a modular and maintainable codebase.
    </p>

    <h2>Key Features:</h2>
    <ol>
        <li><strong>Add Contacts:</strong> Users can input contact details (name, phone number, email, and address) to
            create new entries in the contact book.</li>
        <li><strong>Edit Contacts:</strong> Modify existing contact information, enabling users to update phone
            numbers, emails, or addresses as needed.</li>
        <li><strong>Delete Contacts:</strong> Remove contacts, providing an effective mechanism to manage and organize
            the contact list.</li>
        <li><strong>Search Contacts:</strong> Users can search for specific contacts based on criteria such as name,
            phone number, or email address.</li>
        <li><strong>Display Contacts:</strong> The contact list is presented in a clear and organized manner within the
            console, facilitating easy navigation and interaction.</li>
    </ol>

    <p>This project serves as an exemplary application of OOP principles, resulting in a user-friendly and extensible
        contact management system.</p>

    <h2>Setup Instructions:</h2>

    <ol>
        <li><strong>Development Environment:</strong>
            <ul>
                <li>Ensure a C++ compiler is installed on your system. If not, install one compatible with your
                    operating system.</li>
                <li>The project was developed using Visual Studio IDE, so it's recommended to use Visual Studio for the
                    best compatibility.</li>
            </ul>
        </li>
        <li><strong>Clone the Repository:</strong>
            <ul>
                <li>Clone or download the project repository using the following command:
                    <code>git clone https://github.com/talib-raath/Contact-Book</code></li>
            </ul>
        </li>
        <li><strong>Open Project in Visual Studio:</strong>
            <ul>
                <li>Launch Visual Studio and open the project by selecting the project file (e.g., <code>.sln</code>
                    file) from the cloned repository.</li>
            </ul>
        </li>
        <li><strong>Build the Project:</strong>
            <ul>
                <li>Build the project within the Visual Studio environment. This will compile the source code and
                    generate the executable file.</li>
            </ul>
        </li>
        <li><strong>Run the Application:</strong>
            <ul>
                <li>After successful compilation, run the application within the Visual Studio IDE or locate the
                    generated executable file and run it from the command line.</li>
            </ul>
        </li>
        <li><strong>Interact with the Contact Book:</strong>
            <ul>
                <li>Follow the on-screen instructions to add, edit, delete, search, and display contacts within the
                    console application.</li>
            </ul>
        </li>
    </ol>

    <p>Congratulations! You have successfully set up and run the Contact Book Console App on your system. Enjoy managing
        your contacts in a simple and efficient manner!</p>
</body>

</html>
