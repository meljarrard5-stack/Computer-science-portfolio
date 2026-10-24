# CS 305: Software Security Portfolio
**Melanie Jarrard**

## Client and Software Requirements
Artemis Financial is a financial consulting company that develops individualized financial plans for its clients. The company wanted to improve the security of its web application and protect sensitive financial information. My work focused on identifying vulnerabilities, implementing secure communications, and adding checksum verification to help detect changes to data.

## Identifying Vulnerabilities and Coding Securely
One thing I did well was connecting security findings to specific improvements in the application. I reviewed the code and used OWASP Dependency-Check to identify potential vulnerabilities in third-party libraries. Secure coding is important because weaknesses can expose sensitive information or allow unauthorized access. Software security helps a company protect its customers, maintain trust, and reduce the costs associated with security incidents.

## Challenges and Helpful Parts of the Assessment
Interpreting the dependency-check results was one of the most challenging and helpful parts of the assessment. A scanner finding requires further investigation to determine whether it applies to the application. This process helped me understand the importance of reviewing affected versions and supporting evidence before choosing a mitigation or suppressing a false positive.

## Adding Layers of Security
I added layers of security by configuring HTTPS, generating a certificate, and implementing SHA-256 checksum functionality. HTTPS protects information during transmission, while a checksum can help detect changes when compared with a trusted expected value. In future projects, I would combine dependency scanning, manual code review, and security testing. I would prioritize mitigations based on a vulnerability’s severity, its relevance to the application, and the sensitivity of the information involved.

## Checking Functionality and Security
After refactoring, I built and ran the application and checked its HTTPS connection and checksum output. I also reviewed the updated code and ran dependency scanning to look for known vulnerabilities in the application’s libraries. Comparing the results with the earlier assessment helped me evaluate the changes and identify remaining concerns. These checks provided evidence of functionality and security improvements, although no single test can prove that an application is completely secure.

## Useful Tools and Practices
Useful resources included Java’s MessageDigest API, Spring Boot, Maven, Java keytool, and OWASP Dependency-Check. I also gained experience with certificate generation, HTTPS configuration, and reviewing vulnerability reports. Making small changes, testing after each change, and documenting findings are practices I can apply to future assignments and software development work.

## Demonstrating My Skills to Employers
I would show future employers my Artemis Financial Practices for Secure Software Report and relevant examples of the application’s security improvements. This work demonstrates my ability to assess software vulnerabilities, implement secure communications, use cryptographic hashing, and explain technical decisions. It also shows that I consider security throughout development and verify changes through testing and review.
