#lang racket

;a

(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

(define (left-branch mobile)
  (car mobile))

(define (right-branch mobile)
  (cadr mobile))

(define (branch-length branch)
  (car branch))

(define (branch-structure branch)
  (cadr branch))

;b

(define (branch-weight branch)
    (if (not (pair? (branch-structure branch)))
        (branch-structure branch)
        (+ (branch-weight (left-branch (branch-structure branch)))
           (branch-weight (right-branch (branch-structure branch))))))

(define (total-weight mobile)
  (+ (branch-weight (left-branch mobile))
     (branch-weight (right-branch mobile))))

;c

(define (balanced? mobile)
  (cond ((null? mobile) #t)
        ((= (* (branch-length (left-branch mobile)) 
               (branch-weight (left-branch mobile)))
            (* (branch-length (right-branch mobile)) 
               (branch-weight (right-branch mobile)))) (and (if (pair? (branch-structure (left-branch mobile)))
                                                                (balanced? (branch-structure (left-branch mobile)))
                                                                #t)
                                                            (if (pair? (branch-structure (right-branch mobile)))
                                                                (balanced? (branch-structure (right-branch mobile)))
                                                                #t)))
                                                       
        (else #f)))


;d
;(define (make-mobile left right)
;  (list left right))
;(define (make-branch length structure)
;  (list length structure))

(define x (make-mobile (make-branch 4 (make-mobile (make-branch 3 9) (make-branch 88 34))) (make-branch 7 5)))

(define y (make-mobile (make-branch 8 4) (make-branch 4 8)))